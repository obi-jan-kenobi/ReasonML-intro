type name =
  | Name(string);

type email =
  | Email(string);

type person = {
  firstname: name,
  middlename: option(name),
  lastname: name,
};

type verifiedEmail =
  | VerifiedEmail(email);

type contact =
  | Unverified(email)
  | Verified(verifiedEmail);

type street =
  | Street(string);

type streetNumber =
  | StreetNumber(int);

type zip =
  | ZipDe(int)
  | ZipAt(int)
  | ZipPl(string);

type country =
  | DE
  | AT
  | PL;

type storeId =
  | StoreId(int);

type brand =
  | PUC
  | FFE
  | ANSONS;

type address = {
  country,
  zip,
  street,
  number: streetNumber,
};

type store = {
  id: storeId,
  address,
  brand,
};

type deliveryChoice =
  | InvoiceAddress
  | DeliveryAddress(address)
  | StoreDelivery(store);



type customer = {
  name: person,
  contact,
  address,
  store: address,
  delivery: deliveryChoice,
};

let createEmail = str => {
  let re = Js.Re.fromString("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b");
  switch (Js.Re.test(str, re)) {
  | false => None
  | _ => Some(Email(str))
  };
};

let createZip = (zip: string, country) =>
  switch (country) {
  | DE =>
    if (Js.String.length(zip) != 5) {
      None;
    } else {
      switch (int_of_string(zip)) {
      | zip => Some(ZipDe(zip))
      | exception _ => None
      };
    }
  | AT =>
    if (Js.String.length(zip) != 4) {
      None;
    } else {
      switch (int_of_string(zip)) {
      | zip => Some(ZipAt(zip))
      | exception _ => None
      };
    }
  | PL =>
    let re = Js.Re.fromString("\\d{2}-\\d{3}$");
    Js.Re.test(zip, re)
    |> (
      fun
      | false => None
      | _ => Some(ZipPl(zip))
    );
  };

let createName = str =>
  if (Js.String.length(str) <= 50) {
    Some(str);
  } else {
    None;
  };

let verificationService = email =>
  if (email === "voldemort@gmail.com") {
    None;
  } else {
    Some(email);
  };
