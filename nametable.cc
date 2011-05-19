#include "nametable.h"

using namespace std;

/* operator[] - inserts an element or overwrites existing one
 * insert() - inserts an element but does nothing if element already exists
 */
void NameTable::InsertName (Name name, Value val /*= 0*/)
{
  /* Simulate the behaviour of array indexing */
  val = nameTable.size();
  nameTable[name];
  nameTable[name] = val;
}

void NameTable::InsertName (Name *name, Value val)
{
  InsertName(*name, val);
}

void NameTable::RemoveName (Name name)
{
  nameTable.erase(name);
}

void NameTable::RemoveName (Name *name)
{
  RemoveName(*name);
}

name NameTable::LookupName (Name name)
{
  return nameTable[name];
}

name NameTable::LookupName (Name *name)
{
  return LookupName (*name);
}
