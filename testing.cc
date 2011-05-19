#include "nametable.h"
#include <iostream>
#include "name.h"

using namespace std;

int main(int argc, char *argv[])
{
  NameTable nt;
  nt.InsertName("SimeonSimeonov");

  //  cout << nt.Lookup("SimeonSimeonov") << endl;

  return 0;
}
