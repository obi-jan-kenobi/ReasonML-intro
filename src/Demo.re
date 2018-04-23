type name = Name(string);
type email = Email(string);

type customer = {
  firstname: name, /* max 50 chars */
  middlename: option(name), /* optional */
  lastname: name, /* max 50 chars */
  email: email,
  isEmailVerfied: bool /* reset wenn email sich aendert */
};


