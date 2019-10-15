open BsChakra;
open Belt;

module Giphy = {
  type state = {
    keywords: string,
    results: Request.t(Result.t(Tenor.resource, string)),
  };

  type action =
    | UpdateKeywords(string)
    | SubmitSearch
    | ReceiveSearchResults(Result.t(Tenor.resource, string))
    | CopyGifUrlToClipboard(string);

  [@react.component]
  let make = () => {
    let fieldRef = React.useRef();
    let (state, dispatch) =
      ReactUpdate.useReducer(
        {keywords: "", results: NotAsked}, (action, state) =>
        switch (action) {
        | UpdateKeywords(keywords) => Update({...state, keywords})
        | SubmitSearch =>
          UpdateWithSideEffects(
            {...state, results: Loading},
            self => {
              Tenor.search(~keywords=self.state.keywords, ())
              |> Js.Promise.then_(data => {
                   self.send(ReceiveSearchResults(Result.Ok(data)));
                   Js.Promise.resolve();
                 })
              |> Js.Promise.catch(err => {
                   Js.log(err);
                   self.send(ReceiveSearchResults(Error("")));
                   Js.Promise.resolve();
                 })
              |> ignore;
              None;
            },
          )
        | ReceiveSearchResults(results) =>
          Update({...state, results: Done(results)})
        | CopyGifUrlToClipboard(url) =>
          SideEffects(
            _ => {
              Js.log(url);
              None;
            },
          )
        }
      );

    <Drawer
      initialFocusRef=fieldRef placement=`right isOpen=true onClose={() => ()}>
      <DrawerOverlay />
      <DrawerContent>
        <DrawerCloseButton />
        <DrawerHeader borderBottomWidth="1px">
          "Search on giphy"->React.string
        </DrawerHeader>
        <DrawerBody overflow="scroll">
          <Stack marginBottom={All(Theme(4))}>
            <FormLabel htmlFor="search"> "Keywords"->React.string </FormLabel>
            <Input
              _type=`text
              id="search"
              ref=fieldRef
              onChange={event => {
                let value = event->ReactEvent.Synthetic.target##value;
                dispatch(UpdateKeywords(value));
              }}
              placeholder="omg, wtf, damn..."
            />
          </Stack>
          {switch (state.results) {
           | NotAsked => React.null
           | Loading => <Spinner color=`blue500 size=`md />
           | Done(Error(err)) => <Text> err->React.string </Text>
           | Done(Ok(data)) =>
             <Stack wrap={All(`wrap)} spacing=8>
               {data.results
                ->Array.map(result =>
                    result.media
                    ->Array.get(0)
                    ->Option.mapWithDefault(
                        React.null, (medias: Tenor.medias) =>
                        <Box key={result.id}>
                          <Button
                            variant=`outline
                            height={All("auto")}
                            paddingLeft={All("0px")}
                            paddingRight={All("0px")}
                            padding={All("8px")}
                            onClick={_ =>
                              dispatch(CopyGifUrlToClipboard(medias.gif.url))
                            }>
                            <Image
                              width={All("300px")}
                              rounded="4px"
                              src={medias.gif.url}
                            />
                          </Button>
                        </Box>
                      )
                  )
                ->React.array}
               <Button variant=`ghost> "More"->React.string </Button>
             </Stack>
           }}
        </DrawerBody>
        <DrawerFooter borderTopWidth="1px">
          <Button
            variant=`outline marginRight={All("10px")} onClick={_ => ()}>
            "Cancel"->React.string
          </Button>
          <Button variantColor=`blue onClick={_ => dispatch(SubmitSearch)}>
            "Submit"->React.string
          </Button>
        </DrawerFooter>
      </DrawerContent>
    </Drawer>;
  };
};

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
        <Box> <Hour /> <FavoriteLinks /> <Giphy /> </Box>
      </Flex>
    </ThemeProvider>;
  };
};

ReactDOMRe.renderToElementWithId(<App />, "root");