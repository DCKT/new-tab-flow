open BsChakra__Types;

[@bs.module "@chakra-ui/core"] [@react.component]
external make:
  (
    ~children: React.element,
    ~variantColor: string=?,
    ~size: 'size=?,
    ~variant: [@bs.string] [ | `solid | `ghost | `outline | `link]=?,
    ~_type: [@bs.string] [ | `submit | `button]=?,
    ~leftIcon: string=?,
    ~rightIcon: string=?,
    ~isLoading: bool=?,
    ~isDisabled: bool=?,
    ~loadingText: string=?,
    ~ariaLabel: string=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~paddingLeft: 'pLef=?,
    ~paddingRight: 'pRig=?,
    ~padding: 'p=?,
    ~width: 'w=?,
    ~height: 'h=?
  ) =>
  React.element =
  "Button";

let makeProps =
    (
      ~size: option(responsiveValue(buttonSize))=?,
      ~variantColor: option(variantColor)=?,
      ~width: option(responsiveValue(string))=?,
      ~height: option(responsiveValue(string))=?,
      ~paddingLeft: option(responsiveValue(string))=?,
      ~paddingRight: option(responsiveValue(string))=?,
      ~padding: option(responsiveValue(string))=?,
    ) =>
  makeProps(
    ~size=?size->extractProps(buttonSizeToJs),
    ~variantColor=?variantColor->mapToVariantColor,
    ~width=?width->extractProps(v => v),
    ~height=?height->extractProps(v => v),
    ~paddingRight=?paddingRight->extractProps(v => v),
    ~paddingLeft=?paddingLeft->extractProps(v => v),
    ~padding=?padding->extractProps(v => v),
  );