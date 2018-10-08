#ifndef SYNTAXIC_ANALYZER_H
#define SYNTAXIC_ANALYZER_H

#include <vector>

#include "../Lexical/LexicalAnalyzer.h"

class SyntaxicAnalyzer
{
  private:
  	void buildTree(std::vector<Lexeme*> vLexemes);

  public:
	bool analyze(std::vector<Lexeme*> vLexemes);
};

#endif