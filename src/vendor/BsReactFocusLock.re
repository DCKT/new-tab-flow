module FocusLock = {
  [@bs.module "react-focus-lock"] [@react.component]
  external make: (~returnFocus: bool=?, ~persistentFocus: bool=?, ~children: React.element) => React.element =
    "default";
};

module AutoFocusInside = {
  [@bs.module "react-focus-lock"] [@react.component]
  external make: (~children: React.element) => React.element = "AutoFocusInside";
};

module MoveFocusInside = {
  [@bs.module "react-focus-lock"] [@react.component]
  external make: (~children: React.element) => React.element = "MoveFocusInside";
};