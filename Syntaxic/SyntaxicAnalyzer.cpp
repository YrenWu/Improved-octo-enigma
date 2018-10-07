#include "SyntaxicAnalyzer.h"

using namespace std;

bool checkDelimiters(vector<Operation*> vOperation, OperationType validType) 
{
  bool open = false;
  bool valid = false;
  Operation* begin;
  for(auto op : vOperation) {
  	// if we find a parenthesis with unknown type
  	if(op->getLexemeKeyword() == openParenthesis && op->getType() == 0) {
  	  open = true;
      begin = op;
  	}
    // closing parenthesis found, identify parenthesis
  	if(open && op->getType() == 0 && op->getLexemeKeyword() == closeParenthesis) {
  	  op->setType(validType);
  	  begin->setType(validType);
  	  valid = true;
  	}
  }
  return valid;
}

bool isArithmetic(vector<Operation*> vOperation) // TODO: bind to object ?
{
  bool verbose = true;
  bool found = false;

  for (int i = 0; i < vOperation.size() - 2; ++i) {
    int t1 = vOperation[i]->getType();
    int t2 = vOperation[i+1]->getType();
    int t3 = vOperation[i+2]->getType();

   	string first = vOperation[i]->getLexemeType();
   	string firstSymbol = vOperation[i]->getLexemeKeyword();
   	string second = vOperation[i+1]->getLexemeType();
  	string secondSymbol = vOperation[i+1]->getLexemeKeyword();
  	string third = vOperation[i+2]->getLexemeType();
  	string lastSymbol = vOperation[i+2]->getLexemeKeyword();

  	bool correct = false;
  	bool parenthesis = false;
  	if(vOperation[i]->getType() == 0 || vOperation[i+1]->getType() == 0 || vOperation[i+2]->getType() == 0) {
      // if first term is valid second one is an arithmetic symbol and third one is valid
  	  correct = 
  	    ((first == "Identificator" || first == "Numeric") &&
  	    (secondSymbol == "/" || secondSymbol == "*" || secondSymbol == "+" || secondSymbol == "-") &&
  	    (third == "Identificator" || third == "Numeric"))
  	    ;
  	    
  	  parenthesis = checkDelimiters(vOperation, OperationType::Arithmetic);
  	}

  	if(correct || parenthesis) {
  	  found = true;
  	  vOperation[i]->setType(OperationType::Arithmetic);
  	  vOperation[i+1]->setType(OperationType::Arithmetic);
  	  vOperation[i+2]->setType(OperationType::Arithmetic);
  	  if(verbose) {
  	    cout << "   Valid arithmetic operation found : " + 
  	      vOperation[i]->getLexemeKeyword() + " " +
  	      vOperation[i+1]->getLexemeKeyword() + " " +
  	      vOperation[i+2]->getLexemeKeyword() <<
  	    endl;
  	  } 
  	} 
  }
  
  if(!found)
  	return 1;
  return isArithmetic(vOperation);
}

// TODO : function do display valid entries with associated type.
// if unknown type print error

bool SyntaxicAnalyzer::canFollow(vector<Lexeme*> vLine,  bool verbose)
{
  vector<Operation*> vOperation;
  for(auto lexeme : vLine) {
  	vOperation.push_back(new Operation(lexeme));
  }

  isArithmetic(vOperation);

  /* determinate type of operation, return type, if unknown type generate an error */
  return false;
}

bool SyntaxicAnalyzer::checkSyntax(vector<Lexeme*> vLine, bool verbose)
{
  // test if word can start a line
  bool correct = this->canStart(vLine.front(), verbose);
  // if(!correct) return true;

  // test if a word can end a line 
  correct = this->canFinish(vLine.back(), verbose);
  // if(!correct) return true;

  // iterate to check all lexemes
  correct = this->canFollow(vLine, verbose);

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
