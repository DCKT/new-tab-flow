open BsChakra;

type window;
type event;

[@bs.val] external window: window = "window";
[@bs.get] external keyCode: event => int = "keyCode";

[@bs.send]
external addEventListener: (window, string, event => unit) => unit =
  "addEventListener";
[@bs.send]
external removeEventListener: (window, string, event => unit) => unit =
  "addEventListener";

module App = {
  [@react.component]
  let make = () => {
    let drawer = Hooks.useDisclosure();

    React.useEffect1(
      () => {
        let onPress = e => {
          switch (e->keyCode, drawer##isOpen) {
          | (71, false) => drawer##onOpen()
          | _ => ()
          };
        };
        window->addEventListener("keydown", onPress);
        Some(() => window->removeEventListener("keyword", onPress));
      },
      [|drawer##isOpen|],
    );

    <ThemeProvider theme>
      <CSSReset />
      <Flex
        height={All("100%")}
        margin={All(Custom("auto"))}
        justify={All(`center)}
        align={All(`center)}
        padding={All(Theme(4))}>
        <Box>
          <HourWidget />
          <FavoriteLinksWidget />
          <Box position=`absolute right={All("10px")} top={All("10px")}>
            <IconButton
              variant=`ghost
              icon={Theme(`settings)}
              onClick={_ => drawer##onOpen()}
            />
          </Box>
          <Drawer
            placement=`right
            isOpen=drawer##isOpen
            onClose={() => drawer##onClose()}>
            <DrawerOverlay />
            <TenorWidget closeDrawer={() => drawer##onClose()} />
          </Drawer>
        </Box>
      </Flex>
    </ThemeProvider>;
  };
};

ReactDOMRe.renderToElementWithId(<App />, "root");