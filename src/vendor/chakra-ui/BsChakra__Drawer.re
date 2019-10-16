[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~isOpen: bool=?,
    ~placement: [@bs.string] [ | `top | `left | `bottom | `right]=?,
    ~onClose: unit => unit=?,
    ~finalFocusRef: 'a=?,
    ~initialFocusRef: 'b=?
  ) =>
  React.element =
  "Drawer";