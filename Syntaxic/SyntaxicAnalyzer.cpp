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
  for(auto lexeme : vLexemes) {
  	auto node = new Node(*lexeme);
  	vNodes.push_back(node);
  }
  
  this->setNodes(vNodes);
}

void SyntaxicAnalyzer::setNodes(vector<Node*> vNodes)
{
  this->vNodes = vNodes;
}
