[@decco]
type resource = string;

[@decco]
type apiResource = array(resource);

let faviconUrl = (url: resource) => {
  "https://"
  ++ (
    url
    |> Js.String.replace("http://", "")
    |> Js.String.replace("https://", "")
    |> Js.String.split("/")
    |> Array.to_list
    |> List.hd
  )
  ++ "/favicon.ico";
};

let getSiteName = (url: resource) => {
  let chunk =
    url
    |> Js.String.replace("http://", "")
    |> Js.String.replace("https://", "")
    |> Js.String.split(".");

  chunk->Belt.Array.getExn(0)->String.capitalize;
};