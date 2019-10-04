[@bs.val] [@bs.scope "localStorage"] external setItem: (string, string) => unit = "setItem";
[@bs.val] [@bs.scope "localStorage"] external getItem: string => Js.Null.t(string) = "getItem";
[@bs.val] [@bs.scope "localStorage"] external removeItem: string => unit = "removeItem";
[@bs.val] [@bs.scope "localStorage"] external clear: unit => unit = "clear";