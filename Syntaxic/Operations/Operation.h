#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <vector>

#include "../../Lexical/LexicalAnalyzer.h"

#define OPERATOR_AFFECTATION "="

enum OperationType {
  Undefined, Loop, Branch, Instruction, Bool, Comparison, Arithmetic, Affectation, Logical, Incorrect
};

class Operation
{
  private:
  	bool identified;
    OperationType operationType;
    Lexeme* lexeme;

  public:
  	Operation(Lexeme* lexeme);
    void setIdentified();
    void setType(OperationType type);

    bool isIdentified();
    std::string getLexemeType();
    std::string getLexemeKeyword();

    OperationType getType();
    // std::string getKeyword();
    
    // std::string typeToString(OperationType type);
};
