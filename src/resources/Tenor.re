open Belt;

let key = "5281M2M5N4WP";
let baseURL = "https://api.tenor.com/v1/search";

[@decco]
type media = {
  url: string,
  dims: array(int),
  preview: string,
  size: int,
};

[@decco]
type medias = {
  gif: media,
  mp4: media,
};

[@decco]
type result = {
  tags: array(string),
  url: string,
  media: array(medias),
  id: string,
};

[@decco]
type resource = {
  weburl: string,
  results: array(result),
};

let search = (~keywords, ~limit=5, ()) => {
  Axios.get(baseURL ++ {j|?query=$keywords&key=$key&limit=$limit|j})
  |> Js.Promise.then_(res => res##data |> Js.Promise.resolve)
  |> Js.Promise.then_(data =>
       switch (data->resource_decode) {
       | Result.Ok(v) => Js.Promise.resolve(v)
       | Result.Error(err) =>
         Js.log(err);
         Js.Promise.reject(Js.Exn.raiseError("api decode error"));
       }
     );
};