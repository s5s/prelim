#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>

using namespace std;

void GetNumber (ifstream &infp, char &curch, bool &eofile, int &number)
{
  bool _digit = isdigit(curch);
  int i = 10;
  if (!_digit)
    {
      cout << "Not a digit." << endl;
      exit(1);
    }

  while (!eofile && _digit)
    {
      number = number * i + atoi(&curch);
      eofile = (infp.get(curch) == 0);
      _digit = isdigit (curch) != 0;
    }

}

void SkipSpaces (ifstream &infp, char &curch, bool &eofile)
{
  bool _space;
  _space = isspace (curch) != 0;

  if (!_space) //Exit if curch is not a white space
    {
      cout << "Not a white space." << endl;
      exit (1);
    }

  eofile = (infp.get(curch) == 0);
  _space = isspace (curch) != 0;

  while (!eofile && _space)
    {
      eofile = (infp.get(curch) == 0);
      _space = isspace (curch) != 0;
    }
}

int main (int argc, char *argv[])
{
  ifstream inf;
  char ch;
  bool eofile;

  if (argc != 2 || argc > 2)
    {
      cout << "Usage:        " << argv[0] << " [filename]" << endl;
      exit (1);
    }

  inf.open (argv[1]);
  if (!inf)
    {
      cout << "Error: cannot open file " << argv[1] << " for reading"
	   << endl;
      exit (1);
    }

  eofile = (inf.get(ch) == 0);
  int number = 0;
  while (!eofile)
    {
      if (isdigit(ch))
	{
	  GetNumber (inf, ch, eofile, number);
	  cout << number;
	  number = 0;
	}
      else
	{
	  cout << " ";
	  eofile = (inf.get(ch) == 0);
	}
    }
  cout << endl;

  inf.close();
}
