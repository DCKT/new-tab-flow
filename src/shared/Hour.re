open BsChakra;

let hourRef = ref(0.);
let minutesRef = ref(0.);

let toTwoDigitString = number =>
  switch (number) {
  | m when m < 10. => "0" ++ m->Js.Float.toString
  | _ => number->Js.Float.toString
  };

let updateTime = setTime => {
  let today = Js.Date.now()->Js.Date.fromFloat;
  let hour = today->Js.Date.getHours;
  let minutes = today->Js.Date.getMinutes;
  let update = () => {
    hourRef := hour;
    minutesRef := minutes;
    setTime(_ => (hour->toTwoDigitString, minutes->toTwoDigitString));
  };
  switch (hour, minutes) {
  | (hour, _) when hour != hourRef^ => update()
  | (_, minutes) when minutes != minutesRef^ => update()
  | _ => ()
  };
};

[@react.component]
let make = () => {
  let ((hour, minutes), setTime) = React.useState(() => ("", ""));

  React.useEffect0(() => {
    updateTime(setTime);
    Js.Global.setInterval(
      () => {
        updateTime(setTime);
        ();
      },
      1000,
    )
    |> ignore;
    None;
  });

  <Stack isInline=true justify={All(`center)} align={All(`center)}>
    <Heading _as=`h1 color=`white fontSize={All(`xxxxxxl)}>
      hour->React.string
      <span className="blink"> ":"->React.string </span>
      minutes->React.string
    </Heading>
  </Stack>;
};