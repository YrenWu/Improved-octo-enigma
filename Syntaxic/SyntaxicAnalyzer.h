#ifndef SYNTAXIC_ANALYZER_H
#define SYNTAXIC_ANALYZER_H

#include <vector>

#include "../Lexical/LexicalAnalyzer.h"

class SyntaxicAnalyzer
{
  private:
    bool canStart(Lexeme* lex, bool verbose);
    bool canFinish(Lexeme* lex,  bool verbose);
    bool canFollow(Lexeme* current, Lexeme* next,  bool verbose);
    bool checkSyntax(std::vector<Lexeme*> vLine, bool verbose);

  public:
	bool analyze(std::vector<Lexeme*> vLexemes, bool verbose);
};

#endif