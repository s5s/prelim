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

#include "name.h"

using namespace std;

ostream& operator<<(ostream& output, const Name& n)
{
  output << n.Get ();
  return output;
}

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

length Name::NameLength ()
{
  return name.size();
}

void Name::operator= (const Name& name)
{
  Set (name.Get());
}
