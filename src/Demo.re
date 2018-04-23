type name = Name(string);
type email = Email(string);

type person = {
  firstname: name, /* max 50 chars */
  middlename: option(name), /* optional */
  lastname: name, /* max 50 chars */
};

type contact = {
  email: email,
  isEmailVerfied: bool, /* reset wenn email sich aendert */
};

type customer = {
  name: person,
  contact: contact,
};

let createEmail = (str) => {
  let re = Js.Re.fromString("\\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\\.[A-Z]{2,}\\b");
  switch (Js.Re.test(str, re)) {
    | false => None;
    | _ => Some(Email(str));
    };
};

let createName = (str) => {
  if (Js.String.length(str) <= 50) {
    Some(str);
  } else {
    None;
  };
};
