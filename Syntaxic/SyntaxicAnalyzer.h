#ifndef SYNTAXIC_ANALYZER_H
#define SYNTAXIC_ANALYZER_H

#include <vector>

#include "../Lexical/LexicalAnalyzer.h"
#include "Operations/Operation.h"

#define openParenthesis "("
#define closeParenthesis ")"

class SyntaxicAnalyzer
{
  private:
  	std::vector<Operation*> vOperation;
  	bool verbose;

    bool canStart(Lexeme* lex);
    bool canFinish(Lexeme* lex);
    bool canFollow(std::vector<Lexeme*> vLine);
    bool checkSyntax(std::vector<Lexeme*> vLine);
    bool hasArithmetic();
    bool hasAffectation();
    bool checkDelimiters(OperationType validType);

  public:
	bool analyze(std::vector<Lexeme*> vLexemes, bool verbose);
	void setvOperation(std::vector<Operation*> vOperation);
	void setVerbose(bool verbose);
};

#endif