#include "nametable.h"
#include <iostream>
#include "name.h"

using namespace std;

int main(int argc, char *argv[])
{
  NameTable nt;
  nt.InsertName("SimeonSimeonov");
  nt.InsertName ("MaryanaSimeonova");
  nt.InsertName ("VasilLevski");

  cout << nt.LookupName("VasilLevski") << endl;
  nt.LookupName("IvanVasov");
  cout << nt.LookupName("IvanVasov") << endl;
  cout << nt.LookupName("VasilLevski") << endl;

  cout << nt.LookupName("Logitech") << endl;

  return 0;
}
