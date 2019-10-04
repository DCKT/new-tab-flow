open Belt;

[@decco]
type resource = string;

[@decco]
type apiResource = array(resource);

let faviconUrl = (url: resource) => {
  switch (Js.String.split(".", url)) {
  | [|start, end_|] => start ++ "." ++ Js.String.split("/", end_)->Array.getExn(0) ++ "/favicon.ico"
  | _ => ""
  };
};

let getSiteName = (url: resource) => {
  let chunk = url |> Js.String.replace("http://", "") |> Js.String.replace("https://", "") |> Js.String.split(".");

  chunk->Array.getExn(0)->String.capitalize;
};