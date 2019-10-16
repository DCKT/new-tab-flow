open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~src: string,
    ~fallbackSrc: string=?,
    ~alt: string=?,
    ~size: 'size=?,
    ~width: 'width=?,
    ~height: 'height=?,
    ~onLoad: unit => unit=?,
    ~onError: unit => unit=?,
    ~rounded: string=?,
    ~objectFit: string=?
  ) =>
  React.element =
  "Image";

let makeProps =
    (
      ~size: option(responsiveValue(string))=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(v => v),
    ~width=?width->extractProps(v => v),
    ~height=?height->extractProps(v => v),
  );