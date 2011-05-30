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
    /* Reason I did this instead of map<int, Name> is because with int
     * as key to lookup a namestring you have to iterate through the whole
     * table and compare values. This will have at least a linear O(N) cost
     * whereas a map<Name, int> has a O(log(N)) cost since map is implemented
     * as a BST.
     * Also the Name type should make it easier to handle and work with names.
     */
    std::map<Name, Value,Compare> nameTable;
  public:
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
