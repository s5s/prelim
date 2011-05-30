/* This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Simeon Simeonov <sss41@cam.ac.uk>
 */

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
  map<Name, Value,Compare>::iterator it;
  it = nameTable.find (name);
  /* Name is not present in table */
  if (it == nameTable.end())
    InsertName (name);
  return nameTable[name];
}

Value NameTable::LookupName (namestring str)
{
  /* Since the map has Names as value first create the Name
   * and then look for that object */
  Name name (str);
  return LookupName (name);
}

void NameTable::PrintTable () const
{
  cout << "Table contents:" << endl;
  cout << "Key       Value" << endl;
  map<Name, Value,Compare>::const_iterator it;

  for (it=nameTable.begin(); it != nameTable.end(); it++)
    cout << (*it).first.Get() << "    " << (*it).second << endl;
}

void NameTable::WriteName (Name name) const
{
  cout << name.Get();
}
