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
    let (state, dispatch) =
      ReactUpdate.useReducer({keywords: "", results: NotAsked}, (action, state) =>
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
        | ReceiveSearchResults(results) => Update({...state, results: Done(results)})
        | CopyGifUrlToClipboard(url) =>
          SideEffects(
            _ => {
              Js.log(url);
              None;
            },
          )
        }
      );

    <Modal size={All(`lg)} isOpen=true onClose={() => ()} isCentered=true>
      <ModalOverlay />
      <ModalContent>
        <form
          onSubmit={e => {
            e->ReactEvent.Synthetic.preventDefault;
            dispatch(SubmitSearch);
          }}>
          <ModalHeader> "Search on giphy"->React.string </ModalHeader>
          <ModalCloseButton />
          <ModalBody>
            <Stack isInline=true spacing=5 align={All(`flexEnd)}>
              <FormControl>
                <Input
                  _type=`text
                  id="url"
                  onChange={event => {
                    let value = event->ReactEvent.Synthetic.target##value;
                    dispatch(UpdateKeywords(value));
                  }}
                  placeholder="omg"
                />
              </FormControl>
              <IconButton icon={Theme(`search)} _type=`submit variantColor=`blue />
            </Stack>
            {switch (state.results) {
             | NotAsked => React.null
             | Loading => <Spinner />
             | Done(Error(err)) => <Text> err->React.string </Text>
             | Done(Ok(data)) =>
               <Stack wrap={All(`wrap)} spacing=8>
                 {data.results
                  ->Array.map(result =>
                      result.media
                      ->Array.get(0)
                      ->Option.mapWithDefault(React.null, (medias: Tenor.medias) =>
                          <Box key={result.id}>
                            <Button
                              variant=`outline
                              height={All("auto")}
                              paddingLeft={All("0px")}
                              paddingRight={All("0px")}
                              padding={All("8px")}
                              onClick={_ => dispatch(CopyGifUrlToClipboard(medias.gif.url))}>
                              <Image width={All("300px")} rounded="4px" src={medias.gif.url} />
                            </Button>
                          </Box>
                        )
                    )
                  ->React.array}
               </Stack>
             }}
          </ModalBody>
        </form>
      </ModalContent>
    </Modal>;
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