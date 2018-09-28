#include "Node.h"

using namespace std;

Node::Node(Lexeme lexeme)
{
   this->lexeme = &lexeme;
}

/* Node* Node::getChildrenNode()
{

}

Node* Node::getParentNode()
{

}*/

Lexeme* Node::getLexeme()
{
  return this->lexeme;
}
