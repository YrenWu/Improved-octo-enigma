#ifndef NODE_H
#define NODE_H

#include "../../Lexical/LexicalAnalyzer.h"

class Node
{
  private:
  	Node* parent;
  	Node* children;
  	Lexeme* lexeme;
  	std::vector<Node*> vNodes;

  public:
  	Node(Lexeme lexeme);

    bool isLeaf(); 	// If node have no children, is the last leaf
    bool isRoot(); 	// First parent node

    Node* getChildrenNode();
    Node* getParentNode();
    Lexeme getLexeme();
};

#endif