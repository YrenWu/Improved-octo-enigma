#ifndef SYNTAXIC_ANALYZER_H
#define SYNTAXIC_ANALYZER_H

#include <vector>

#include "../Lexical/LexicalAnalyzer.h"

class Node
{
  private:
  public:
    bool haveChildren();
};

class SyntaxicAnalyzer
{
  private:

  public:
	bool analyze(std::vector<Lexeme*> vLexemes);
};

#endif