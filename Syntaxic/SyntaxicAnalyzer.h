#ifndef SYNTAXIC_ANALYZER_H
#define SYNTAXIC_ANALYZER_H

#include <vector>

#include "../Lexical/LexicalAnalyzer.h"
#include "Node/Node.h"

class SyntaxicAnalyzer
{
  private:
  	Node* root; // first Node
  	std::vector<Node*> vNodes;

  	void buildTree(std::vector<Lexeme*> vLexemes);

  public:
	bool analyze(std::vector<Lexeme*> vLexemes);

	void setNodes(std::vector<Node*> vNodes);
	void setRoot(Node* root);
};

#endif