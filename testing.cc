#include "nametable.h"
#include <iostream>
#include "name.h"

using namespace std;

int main(int argc, char *argv[])
{
  Name n1, n2, n3;

  n1.Set("Aaron");
  n2.Set("Ian");
  n3 = n1;

  cout << n3 << endl;

  NameTable nt;

  nt.InsertName (n1);
  nt.InsertName ("Simeon");

  /* The LookupName function searches for a name and if found returns the
     position in the array. If not found it adds it to the end of the array.
     That is why even though Ian is was not added to the table it still
     returns a value of 2.
  */


  cout << "Value associated with n3: " << nt.LookupName (n3)
                                         /*See above n3 = n1 */
       << "\nValue associated with simeon: " << nt.LookupName ("Ian")
       << "\nValue associated with Simeon: " << nt.LookupName ("Simeon")
       << endl;


  cout << endl << endl;


  /* Print the whole table */
  nt.PrintTable ();

  return 0;
}
