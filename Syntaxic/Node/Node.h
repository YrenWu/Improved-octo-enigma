#ifndef NODE_H
#define NODE_H

#include "../../Lexical/LexicalAnalyzer.h"

class Node
{
  private:
  	//Node* parent;
  	//Node* children;
  	Lexeme* lexeme;
  	std::vector<Node*> vNodes;

  public:
  	Node(Lexeme lexeme);

    //Node* getChildrenNode();
    //Node* getParentNode();
    Lexeme* getLexeme();
};

#endif