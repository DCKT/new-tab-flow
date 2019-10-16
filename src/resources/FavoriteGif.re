open Belt;

let storageKey = "favoriteGifs";

[@decco]
type resource = array(string);

type state = resource;

type action =
  | SaveGif(string)
  | RemoveGif(string);

let initialState =
  switch (LocalStorage.getItem(storageKey)->Js.Null.toOption) {
  | None => [||]
  | Some(v) => v->Js.Json.parseExn->resource_decode->Result.getExn
  };

let api =
  Restorative.createStore(initialState, (state, action) =>
    switch (action) {
    | SaveGif(url) => state->Array.concat([|url|])
    | RemoveGif(url) => state->Array.keep(u => u !== url)
    }
  );

let syncToStorage = () =>
  storageKey->LocalStorage.setItem(
    api.getState()->resource_encode->Js.Json.stringify,
  );

let save = url => {
  api.dispatch(SaveGif(url));
  syncToStorage();
};
let remove = url => {
  api.dispatch(RemoveGif(url));
  syncToStorage();
};