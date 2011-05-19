#ifndef NAMETABLE_H
#define NAMETABLE_H

#include <map>
#include <string>
#include <iostream>
#include "namestring.h"
#include "name.h"

typedef int Value;

class Compare
{
 public:
  bool operator() (const Name &thisname, const Name &otherName) const;
};

  class NameTable
  {
  private:
    std::map<Name, Value,Compare> nameTable;
  public:
    //NameTable ();
    void InsertName (Name name, Value val = 0);
    void InsertName (namestring str, Value val = 0);
    void RemoveName (Name name);
    void RemoveName (Name *name);
    Value LookupName (Name name);
    Value LookupName (namestring str);
    void PrintTable () const;
    void WriteName (Name name) const;
  };

#endif // NAMETABLE_H
