#ifndef NAMETABLE_H
#define NAMETABLE_H

#include <map>
#include <string>
#include "namestring.h"
#include "name.h"

typedef int Value;

  class NameTable
  {
  private:
    std::map<Name*, Value> nameTable;
  public:
    //NameTable ();
    void InsertName (Name name, Value val = 0);
    void InsertName (Name *name, Value val = 0);
    void RemoveName (Name name);
    void RemoveName (Name *name);
    Value LookupName (Name name);
    Value LookupName (Name *name);
  };

#endif // NAMETABLE_H
