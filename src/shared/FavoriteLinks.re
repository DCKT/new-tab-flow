open BsChakra;
open Belt;
open BsReactFocusLock;

type state = {links: list(FavLink.resource)};

type action =
  | FetchStoredLinks
  | ReceiveStoredLinks(FavLink.apiResource)
  | AddLink(string)
  | RemoveLink(string)
  | SaveLinksInStorage;

[@react.component]
let make = () => {
  let (newLink, setNewLink) = React.useState(() => "");
  let (popover, setPopover) = React.useState(() => false);
  let firstFieldRef = React.useRef(_ => None);

  let (state, dispatch) =
    ReactUpdate.useReducer({links: []}, (action, state) =>
      switch (action) {
      | FetchStoredLinks =>
        SideEffects(
          self => {
            let links = LocalStorage.getItem("links")->Js.Null.toOption;

            switch (links) {
            | None => self.send(ReceiveStoredLinks([||]))
            | Some(links) =>
              let parsedLinks = links->Js.Json.parseExn->FavLink.apiResource_decode;

              switch (parsedLinks) {
              | Result.Error(err) =>
                Js.log2("Parse error", err);
                self.send(ReceiveStoredLinks([||]));
              | Result.Ok(v) => self.send(ReceiveStoredLinks(v))
              };
            };

            None;
          },
        )
      | ReceiveStoredLinks(links) => Update({links: links->List.fromArray})
      | AddLink(link) =>
        UpdateWithSideEffects(
          {links: [link, ...state.links]},
          ({send}) => {
            send(SaveLinksInStorage);
            setPopover(_ => false);
            None;
          },
        )

      | RemoveLink(link) =>
        UpdateWithSideEffects(
          {links: state.links->List.keep(l => l != link)},
          ({send}) => {
            send(SaveLinksInStorage);
            None;
          },
        )

      | SaveLinksInStorage =>
        SideEffects(
          self => {
            LocalStorage.setItem(
              "links",
              self.state.links->List.toArray->FavLink.apiResource_encode->Js.Json.stringify,
            );
            None;
          },
        )
      }
    );

  React.useEffect0(() => {
    dispatch(FetchStoredLinks);
    None;
  });

  <>
    <Stack isInline=true justify={All(`center)} marginTop={All(Theme(3))}>
      <Stack spacing=10>
        {switch (state.links) {
         | [] => React.null
         | links =>
           <Box bg=`white padding={All(Theme(4))} boxShadow={All(Theme(`sm))}>
             <Stack
               isInline=true justify={All(`center)} align={All(`center)} maxWidth={All("600px")} wrap={All(`wrap)}>
               {links
                ->List.map(link =>
                    <Box marginTop={All(Theme(2))} marginBottom={All(Theme(2))} position=`relative>
                      <Box position=`absolute top={All("-10px")} right={All("5px")}>
                        <IconButton
                          size={All(`sm)}
                          variant=`ghost
                          icon={Theme(`delete)}
                          onClick={_ => dispatch(RemoveLink(link))}
                        />
                      </Box>
                      <Link href=link>
                        <Stack spacing=2 width={All("130px")}>
                          <Flex
                            bg=`gray200
                            rounded={All(`full)}
                            width={All("50px")}
                            height={All("50px")}
                            justify={All(`center)}
                            align={All(`center)}
                            margin={All(Custom("auto"))}>
                            <Box width={All("16px")} height={All("16px")}>
                              <AspectRatioBox maxWidth={All("16px")} ratio={4 / 3}>
                                <Image src={FavLink.faviconUrl(link)} />
                              </AspectRatioBox>
                            </Box>
                          </Flex>
                          <Text isTruncated=true textAlign={All(`center)}>
                            {link->FavLink.getSiteName->React.string}
                          </Text>
                        </Stack>
                      </Link>
                    </Box>
                  )
                ->List.toArray
                ->React.array}
             </Stack>
           </Box>
         }}
        <Popover isOpen=popover onOpen={() => setPopover(_ => true)} onClose={() => setPopover(_ => false)}>
          <PopoverTrigger>
            <Box maxWidth={All("200px")} margin={All(Custom("auto"))}>
              <Button leftIcon="add" size={All(`lg)}> "Add link"->React.string </Button>
            </Box>
          </PopoverTrigger>
          <PopoverContent>
            <PopoverArrow />
            <FocusLock returnFocus=true persistentFocus=false>
              <Box padding={All(Theme(5))}>
                <form
                  onSubmit={e => {
                    e->ReactEvent.Synthetic.preventDefault;
                    dispatch(AddLink(newLink));
                  }}>
                  <Stack isInline=true spacing=5 align={All(`flexEnd)}>
                    <FormControl>
                      <Input
                        _type=`url
                        id="url"
                        ref=firstFieldRef
                        onChange={event => {
                          let value = event->ReactEvent.Synthetic.target##value;
                          setNewLink(_ => value);
                        }}
                        placeholder="https://"
                      />
                    </FormControl>
                    <Button _type=`submit variantColor=`blue> "Add"->React.string </Button>
                  </Stack>
                </form>
              </Box>
            </FocusLock>
          </PopoverContent>
        </Popover>
      </Stack>
    </Stack>
  </>;
};