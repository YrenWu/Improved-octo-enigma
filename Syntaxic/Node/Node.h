#ifndef NODE_H
#define NODE_H

class Node
{
  private:
  	Node* parent;
  	Node* children;
  	Lexeme lexeme;

  public:
  	Node(Lexeme lexeme);

    bool isLeaf(); 	// If node have no children, is the last leaf
    bool isRoot(); 	// First parent node

    Node* getChildrenNode();
    Node* getParentNode();

    // getLexeme;
};

#endif