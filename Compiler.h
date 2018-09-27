#ifndef COMPILER_H
#define COMPILER_H

#include <iostream>
#include <fstream>

#include "Lexical/LexicalAnalyzer.h"

#include "Syntaxic/SyntaxicAnalyzer.h"
#include "Semantic/SemanticAnalyzer.h"

class Compiler {
  private:
	std::string filename;
	LexicalAnalyzer lexical;
	SyntaxicAnalyzer syntaxic;
    // SemanticAnalyzer semantic;

  public:
  	Compiler(std::string filename);
	void read(bool verbose);
};

#endif 
