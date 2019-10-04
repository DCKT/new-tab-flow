open BsChakra;

module App = {
  [@react.component]
  let make = () => {
    <ThemeProvider theme>
      <CSSReset />
      <Flex
        height={All("100%")}
        margin={All(Custom("auto"))}
        justify={All(`center)}
        align={All(`center)}
        padding={All(Theme(4))}>
        <Box> <Hour /> <FavoriteLinks /> </Box>
      </Flex>
    </ThemeProvider>;
  };
};

ReactDOMRe.renderToElementWithId(<App />, "root");