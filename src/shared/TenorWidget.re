open BsChakra;
open Belt;

type state = {
  keywords: string,
  results: Request.t(Result.t(Tenor.resource, string)),
  resultLimit: int,
  loadingMore: bool,
};

type action =
  | UpdateKeywords(string)
  | SearchGif
  | SubmitSearch
  | ReceiveSearchResults(Result.t(Tenor.resource, string))
  | CopyGifUrlToClipboard(string)
  | LoadMoreResults
  | CleanSearch;

[@react.component]
let make = (~closeDrawer) => {
  let initialState = {
    keywords: "",
    results: NotAsked,
    resultLimit: 5,
    loadingMore: false,
  };
  let (state, dispatch) =
    ReactUpdate.useReducer(initialState, (action, state) =>
      switch (action) {
      | UpdateKeywords(keywords) => Update({...state, keywords})
      | SearchGif =>
        SideEffects(
          self => {
            Tenor.search(
              ~keywords=self.state.keywords,
              ~limit=self.state.resultLimit,
              (),
            )
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
      | SubmitSearch =>
        UpdateWithSideEffects(
          {...state, results: Loading},
          self => {
            self.send(SearchGif);
            None;
          },
        )
      | ReceiveSearchResults(results) =>
        Update({...state, loadingMore: false, results: Done(results)})
      | CopyGifUrlToClipboard(url) =>
        SideEffects(
          _ => {
            BsCopyToClipboard.copy(url);
            closeDrawer();
            None;
          },
        )
      | LoadMoreResults =>
        UpdateWithSideEffects(
          {...state, resultLimit: state.resultLimit + 5, loadingMore: true},
          self => {
            self.send(SearchGif);
            None;
          },
        )
      | CleanSearch => Update(initialState)
      }
    );

  <DrawerContent>
    <DrawerCloseButton />
    <DrawerHeader borderBottomWidth="1px">
      "Search on Tenor"->React.string
    </DrawerHeader>
    <DrawerBody overflowY="scroll">
      <Stack marginBottom={All(Theme(4))}>
        <form
          onSubmit={e => {
            e->ReactEvent.Synthetic.preventDefault;
            dispatch(SubmitSearch);
          }}>
          <FormLabel htmlFor="search"> "Keywords"->React.string </FormLabel>
          <Box position=`relative>
            <Input
              _type=`text
              id="search"
              value={state.keywords}
              onChange={event => {
                let value = event->ReactEvent.Synthetic.target##value;
                dispatch(UpdateKeywords(value));
              }}
              placeholder="omg, wtf, damn..."
            />
            {switch (state.keywords) {
             | "" => React.null
             | _ =>
               <Box position=`absolute right={All("4px")} top={All("4px")}>
                 <IconButton
                   icon={Theme(`close)}
                   size={All(`sm)}
                   onClick={_ => dispatch(CleanSearch)}
                 />
               </Box>
             }}
          </Box>
        </form>
      </Stack>
      {switch (state.results) {
       | NotAsked => React.null
       | Loading => <Spinner color=`blue500 size=`md />
       | Done(Error(err)) => <Text> err->React.string </Text>
       | Done(Ok(data)) =>
         <Box>
           {data.results
            ->Array.map(result =>
                result.media
                ->Array.get(0)
                ->Option.mapWithDefault(React.null, (medias: Tenor.medias) =>
                    <Box marginBottom={All(Theme(4))} key={result.id}>
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
           <Button
             isLoading={state.loadingMore}
             variant=`ghost
             width={All("100%")}
             onClick={_ => dispatch(LoadMoreResults)}>
             "More"->React.string
           </Button>
         </Box>
       }}
    </DrawerBody>
    <DrawerFooter borderTopWidth="1px">
      <Button
        variant=`outline
        marginRight={All("10px")}
        onClick={_ => closeDrawer()}>
        "Cancel"->React.string
      </Button>
      <Button variantColor=`blue onClick={_ => dispatch(SubmitSearch)}>
        "Submit"->React.string
      </Button>
    </DrawerFooter>
  </DrawerContent>;
};