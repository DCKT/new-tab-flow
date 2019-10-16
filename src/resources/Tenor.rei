type media = {
  url: string,
  dims: array(int),
  preview: string,
  size: int,
};

type medias = {
  gif: media,
  mp4: media,
};

type result = {
  tags: array(string),
  url: string,
  media: array(medias),
  id: string,
};

type resource = {
  weburl: string,
  results: array(result),
};

let search:
  (~keywords: string, ~limit: int=?, unit) => Js.Promise.t(resource);