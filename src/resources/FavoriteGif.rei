type resource = array(string);
type state = resource;

type action =
  | SaveGif(string)
  | RemoveGif(string);

let api: Restorative.api(state, action);

let save: string => unit;
let remove: string => unit;