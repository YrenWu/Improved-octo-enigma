#include <iostream>
#include <vector>

#include "Compiler.h"

using namespace std;

Compiler::Compiler(string filename) 
{
  this->filename = filename;
  LexicalAnalyzer lexical;
}

void Compiler::read(bool verbose) 
{
  ifstream file(this->filename);
  string line;

  if (file.is_open()) {
    int lineNumber = 1;
  	while (getline(file, line)) {
      // Send a line to Lexical Analyzer to build lexemes set
      this->lexical.split(line, lineNumber);
      lineNumber++;
  	}
    this->lexical.analyze(verbose);
  	file.close();
  } else {
  	cout << "Error reading file. Please check the file name" << endl;
  }
}