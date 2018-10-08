#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <vector>
#include <set>

#include "../../Lexical/LexicalAnalyzer.h"

#define OPERATOR_AFFECTATION "="

enum OperationType {
  Undefined, Loop, Branch, Instruction, Bool, Comparison, Arithmetic, Affectation, Logical
};

class Operation
{
  private:
  	bool identified;
    OperationType operationType;
    Lexeme* lexeme;

  public:
  	Operation(Lexeme* lexeme);
  	
  	/* keywords */
	std::set<std::string> oLoop = {{ "while" }};
	std::set<std::string> oBranch = {{ "if" },{ "else" }};
	std::set<std::string> oInstruction = {{ "print" },{ "scan" }};

	/* operators */
	std::set<std::string> oComparison = {{ "==" },{ "!=" },{ "<" },{ "<=" },{ ">=" },{ ">" }};
	std::set<std::string> oLogic = {{ "&&" },{ "||" }};

    void setIdentified();
    void setType(OperationType type);

    bool isIdentified();
    std::string getLexemeType();
    std::string getLexemeKeyword();

    OperationType getType();
};

#endif
