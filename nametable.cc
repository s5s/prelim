#include "nametable.h"

using namespace std;

bool Compare::operator() (const Name &thisName, const Name &otherName) const
{
  return thisName.Get().compare(otherName.Get()) < 0;
}

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

void NameTable::InsertName (namestring str, Value val)
{
  /* Since the map has Names as value first create the Name
   * and then look for that object */
  Name name (str);
  InsertName (name);
}

void NameTable::RemoveName (Name name)
{
  nameTable.erase(name);
}

void NameTable::RemoveName (Name *name)
{
  RemoveName(*name);
}

Value NameTable::LookupName (Name name)
{
  return nameTable[name];
}

Value NameTable::LookupName (namestring str)
{
  /* Since the map has Names as value first create the Name
   * and then look for that object */
  Name name (str);
  return LookupName (name);
}
