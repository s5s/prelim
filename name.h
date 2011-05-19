#ifndef NAME_H
#define NAME_H

#include <iostream>
#include "namestring.h"

typedef unsigned length;

class Name
{
  friend std::ostream& operator<<(std::ostream& output, const Name& n);
 private:
  const unsigned maxlength;
  namestring name;
  namestring FormatName (namestring &str);
 public:
  Name ();
  Name (namestring str);
  Name (namestring *strp);
  namestring Get () const;
  void Set (namestring str);
  void Set (namestring *strp);
  length NameLength ();
};

#endif //NAME_H
