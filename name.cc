#include "name.h"

using namespace std;

Name::Name () : maxlength (8) {}

Name::Name (namestring str) : maxlength (8)
{
  name = FormatName(str);
}

Name::Name (namestring *strp) : maxlength (8)
{
  name = FormatName (*strp);
}

namestring Name::FormatName (namestring &str)
{
  if (str.size() > maxlength)
    {
      str.erase(str.begin() + maxlength, str.end());
    }
  return str;
}

namestring Name::Get () const
{
  return name;
}

void Name::Set (namestring str)
{
  name = FormatName(str);
}

void Name::Set (namestring *strp)
{
  name = FormatName(*strp);
}
