#include <iostream>
#include <vector>

#include "Compiler.h"

using namespace std;

Compiler::Compiler(string filename) 
{
  this->filename = filename;
  LexicalAnalyzer lexical;
}

void Compiler::read() 
{
  ifstream file(this->filename);
  string line;

  if (file.is_open()) {
    int lineNumber = 1;
  	while (getline(file, line)) {
      // Send a line to Lexical Analyzer
      this->lexical.analyze(line, lineNumber);
      lineNumber++;
      // TODO : grammar definition
      // TODO : Syntaxic and semantic analysis and so on ...
  	}
  	file.close();
  } else {
  	cout << "Error reading file. Please check the file name" << endl;
  }
}
