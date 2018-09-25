#include <iostream>

#include "Compiler.h"

using namespace std;

int main(int argc, char *argv[]) 
{
  string source;
  if (argc > 1) {
	source = argv[1];
	Compiler compiler(source);
	compiler.read(true);
  } else {
	cout << "No file specified. Please enter an input file" << endl;
  }
}
