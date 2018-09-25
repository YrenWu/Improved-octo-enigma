#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>
#include "Lexical/LexicalAnalyzer.h"

class Compiler {
  std::string filename;	
  LexicalAnalyzer lexical;
  // SyntaxicAnalyzer
  // SemanticAnalyzer

  public:
  	Compiler(std::string filename);
	void read();
};

#endif 
