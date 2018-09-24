#include "Compiler.h"

using namespace std;

Compiler::Compiler(string filename) 
{
  this->filename = filename;
}

void Compiler::read() 
{
  ifstream file(this->filename);
  string line; 
  if (file.is_open()) {

  	while (getline(file, line)) {
  	  cout << line << endl;
       
      // TODO : grammar definition
      // TODO : class LexicalAnalyzer + call to checkLexeme(line);
      // TODO : Syntaxic and semantic analysis and so on ...
  	}
  	file.close();
  } else {
  	cout << "Error reading file. Please check the file name" << endl;
  }
}
