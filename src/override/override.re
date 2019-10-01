open Document;

module Hour = {
  let hourRef = ref(0.);
  let minutesRef = ref(0.);

  let init = () => {
    let hourElement = document->querySelector(".js-hour");
    let setHour = () => {
      let today = Js.Date.now()->Js.Date.fromFloat;
      let hour = today->Js.Date.getHours;
      let minutes = today->Js.Date.getMinutes;

      let update = () => {
        hourRef := hour;
        minutesRef := minutes;
        hourElement->Node.setInnerHTML({j|$hour<span>:</span>$minutes|j});
      };

      switch (hour, minutes) {
      | (hour, _) when hour != hourRef^ => update()
      | (_, minutes) when minutes != minutesRef^ => update()
      | _ => ()
      };
    };

    setHour();

    Js.Global.setInterval(
      () => {
        setHour();
        ();
      },
      1000,
    )
    |> ignore;
  };
};

module QuickLinks = {
  let init = () => {
    let addButtonElement = document->querySelector(".js-quick-links-add");
    let modalElement = document->querySelector(".js-quick-links-modal");
    let modalOverlayElement =
      document->querySelector(".js-quick-links-modal-overlay");
    let formElement = document->querySelector(".js-quick-links-form");
    let inputElement = document->querySelector(".js-quick-links-form-input");

    let toggleModal = () =>
      modalElement
      ->Node.classList
      ->Node.Classlist.toggle("quick-links-modal--visible");

    addButtonElement->Node.addEventListener(`click, _event => toggleModal());

    modalOverlayElement->Node.addEventListener(`click, _event =>
      toggleModal()
    );

    formElement->Node.addEventListener(
      `submit,
      event => {
        event->Event.preventDefault();
        Js.log(inputElement->Node.value);
        toggleModal();
      },
    );
  };
};

document->addEventListener(
  `DOMContentLoaded,
  () => {
    Hour.init();
    QuickLinks.init();
    ();
  },
);