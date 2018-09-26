#include <cstring>

#include "Compiler.h"

using namespace std;

int main(int argc, char *argv[]) 
{
  string source;
  if (argc > 1) {
	source = argv[argc - 1];
	bool verbose = (strcmp(argv[1], "-v") == 0) ? true : false;
	Compiler compiler(source);
	compiler.read(verbose);
  } else {
	cout << "No file specified. Please enter an input file" << endl;
  }
}
