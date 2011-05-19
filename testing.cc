#include "nametable.h"
#include <iostream>
#include "name.h"

using namespace std;

int main(int argc, char *argv[])
{
  NameTable nt;
  //namestring str = "SimeonSimeonov";
  nt.InsertName("SimeonSimeonov");
  nt.InsertName ("MaryanaSimeonova");
  nt.InsertName ("VasilLevski");

  cout << nt.LookupName("VasilLevski") << endl;

  return 0;
}
