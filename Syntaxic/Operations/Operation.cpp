#include "Operation.h"

using namespace std;

Operation::Operation(Lexeme* lex)
{
  this->lexeme = lex;
  this->identified = false;
  this->operationType = OperationType::Undefined; // TODO: function tostring enum
}

bool Operation::isIdentified()
{
  return this->identified;
}

string Operation::getLexemeType()
{
  return this->lexeme->typeToString(lexeme->getType());
}

string Operation::getLexemeKeyword()
{
  return this->lexeme->getKeyword();
}

void Operation::setType(OperationType type)
{
  this->operationType = type;
}

OperationType Operation::getType()
{
  return this->operationType;
}