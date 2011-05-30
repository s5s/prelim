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
  void operator= (const Name& rhs);
};

#endif //NAME_H
