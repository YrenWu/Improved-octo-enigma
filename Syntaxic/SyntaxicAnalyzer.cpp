#include "SyntaxicAnalyzer.h"

using namespace std;

bool SyntaxicAnalyzer::analyze(vector<Lexeme*> vLexemes)
{
  // Build Nodes with Lexemes
  this->buildTree(vLexemes);
 
  // 2 - Recursively build syntax tree
	// Check if node have children 
	// Yes : Continue 
	// No : Stop

  // 3 - Check syntax through all nodes
  return false;
}

void SyntaxicAnalyzer::buildTree(vector<Lexeme*> vLexemes)
{
  vector<Node*> vNodes;
  // int current = 0;

  for(auto lexeme : vLexemes) {
  	// TODO : Check if node have a parent or a children and built it

  	/*if(current != lexeme->getLine()){
      current = lexeme->getLine();
      // new line, first of the line 
  	}*/

  	auto node = new Node(*lexeme);
  	vNodes.push_back(node);

  	if(lexeme->getLine() == 1 && lexeme->getPosition() == 1) {
  	  // First lexem of code, root element
  	  this->setRoot(node);
  	}
  }
  this->setNodes(vNodes);
}

void SyntaxicAnalyzer::setNodes(vector<Node*> vNodes)
{
  this->vNodes = vNodes;
}

void SyntaxicAnalyzer::setRoot(Node* root)
{
  this->root = root;
}
