#ifndef NAME_H
#define NAME_H

#include "namestring.h"

class Name
{
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
};

#endif //NAME_H
