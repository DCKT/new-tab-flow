type document;

module Event = {
  type t;

  [@bs.send] external preventDefault: (t, unit) => unit = "preventDefault";
};

module Node = {
  type t;

  module Classlist = {
    type t;

    [@bs.send] external toggle: (t, string) => unit = "toggle";
  };

  [@bs.get] external value: t => string = "value";
  [@bs.set] external setText: (t, string) => unit = "text";
  [@bs.set] external setInnerHTML: (t, string) => unit = "innerHTML";
  [@bs.send]
  external addEventListener:
    (t, [@bs.string] [ | `click | `submit], Event.t => unit) => unit =
    "addEventListener";

  [@bs.get] external classList: t => Classlist.t = "classList";
};

[@bs.val] external document: document = "document";

[@bs.send]
external addEventListener:
  (document, [@bs.string] [ | `DOMContentLoaded], unit => unit) => unit =
  "addEventListener";

[@bs.send]
external querySelector: (document, string) => Node.t = "querySelector";
[@bs.send]
external querySelectorAll: (document, string) => Node.t = "querySelectorAll";

type response;

[@bs.val] external fetch: string => Js.Promise.t(response) = "fetch";