#include "SyntaxicAnalyzer.h"

using namespace std;

bool SyntaxicAnalyzer::canFollow(Lexeme* current, Lexeme* next,  bool verbose)
{
	// TODO : check if it is a correct following term
	// determinate type of operation (ex: affectation, artimetic expr, condition...)

	return false;
}

bool SyntaxicAnalyzer::checkSyntax(vector<Lexeme*> vLine, bool verbose)
{
  // test if word can start a line
  bool correct = this->canStart(vLine.front(), verbose);
  if(!correct) return true;

  // test if a word can end a line 
  correct = this->canFinish(vLine.back(), verbose);
  if(!correct) return true;

  // iterate to check all lexemes
  // correct = this->canFollow(current, next, verbose);
  // if(!correct) return true;

  return false;
}

bool SyntaxicAnalyzer::analyze(vector<Lexeme*> vLexemes, bool verbose)
{
  int line = 1;
  vector<Lexeme*> vLine; 

  for(auto lexeme : vLexemes) {
    if(line != lexeme->getLine()) {
      line++;
      bool error = this->checkSyntax(vLine, verbose);
      // return true if there is any error
      if(error) return true;
      vLine.clear();
      vLine.push_back(lexeme);
    } else {
      vLine.push_back(lexeme);
    }
  }

  return false;
}

bool SyntaxicAnalyzer::canStart(Lexeme* lex, bool verbose)
{
  /* check if first term can be a starting word */
  string type = lex->typeToString(lex->getType());
  string keyword = lex->getKeyword();
  bool correct = true;

  if(type == "Keyword" && keyword == "else") {
  	if(verbose) cout << "   /!\\ ERROR : else is not a valid starting instruction" << endl;
   	correct = false; 
  } else if (type == "Operator") {
  	if(verbose) cout << "   /!\\ ERROR : cannot start with operator" << endl;
    correct = false;
  } else {
  	if(verbose) cout << "   " + keyword + " is a valid starting instruction" << endl;
  }

  return correct;
}

bool SyntaxicAnalyzer::canFinish(Lexeme* lex, bool verbose)
{
  /* check if first term can be an ending word */
  string type = lex->typeToString(lex->getType());
  string keyword = lex->getKeyword();
  bool correct = true;

  if(type == "Keyword" && (keyword != "true" && keyword != "false")) {
  	if(verbose) cout << "   /!\\ ERROR : this keyword is not a valid ending instruction" << endl;
   	correct = false; 
  } else if (type == "Operator") {
  	if(verbose) cout << "   /!\\ ERROR : cannot end with operator" << endl;
    correct = false;
  } else if (keyword == "(") { // TODO: separate ending and starting delimiters
  	if(verbose) cout << "   /!\\ ERROR : ending delimiter is missing" << endl;
    correct = false;
  } else {
  	if(verbose) cout << "   " + keyword + " is a valid ending instruction" << endl;
  }

  return correct;
}
