#include "SyntaxicAnalyzer.h"

using namespace std;

bool SyntaxicAnalyzer::checkDelimiters(OperationType validType) 
{
  bool open = false;
  bool valid = false;
  Operation* begin;
  for(auto op : this->vOperation) {
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

bool SyntaxicAnalyzer::isArithmetic()
{
  bool verbose = true;
  bool found = false;

  for (int i = 0; i < this->vOperation.size() - 2; ++i) {
    int t1 = this->vOperation[i]->getType();
    int t2 = this->vOperation[i+1]->getType();
    int t3 = this->vOperation[i+2]->getType();

   	string first = this->vOperation[i]->getLexemeType();
   	string firstSymbol = this->vOperation[i]->getLexemeKeyword();
   	string second = this->vOperation[i+1]->getLexemeType();
  	string secondSymbol = this->vOperation[i+1]->getLexemeKeyword();
  	string third = this->vOperation[i+2]->getLexemeType();
  	string lastSymbol = this->vOperation[i+2]->getLexemeKeyword();

  	bool correct = false;
  	bool parenthesis = false;
  	if(this->vOperation[i]->getType() == 0 || this->vOperation[i+1]->getType() == 0 || this->vOperation[i+2]->getType() == 0) {
      // if first term is valid second one is an arithmetic symbol and third one is valid
  	  correct = 
  	    ((first == "Identificator" || first == "Numeric") &&
  	    (secondSymbol == "/" || secondSymbol == "*" || secondSymbol == "+" || secondSymbol == "-") &&
  	    (third == "Identificator" || third == "Numeric"))
  	    ;
  	    
  	  parenthesis = this->checkDelimiters(OperationType::Arithmetic);
  	}

  	if(correct || parenthesis) {
  	  found = true;
  	  this->vOperation[i]->setType(OperationType::Arithmetic);
  	  this->vOperation[i+1]->setType(OperationType::Arithmetic);
  	  this->vOperation[i+2]->setType(OperationType::Arithmetic);
  	  if(verbose) {
  	    cout << "   Valid arithmetic operation found : " + 
  	      this->vOperation[i]->getLexemeKeyword() + " " +
  	      this->vOperation[i+1]->getLexemeKeyword() + " " +
  	      this->vOperation[i+2]->getLexemeKeyword() <<
  	    endl;
  	  } 
  	} 
  }
  
  if(!found)
  	return 1;
  return this->isArithmetic();
}

// TODO : function do display valid entries with associated type.
// if unknown type print error

bool SyntaxicAnalyzer::canFollow(vector<Lexeme*> vLine)
{
  vector<Operation*> vOperation;
  for(auto lexeme : vLine) {
  	vOperation.push_back(new Operation(lexeme));
  }
  this->setvOperation(vOperation);
  this->isArithmetic();

  /* determinate type of operation, return type, if unknown type generate an error */
  return false;
}

bool SyntaxicAnalyzer::checkSyntax(vector<Lexeme*> vLine)
{
  // test if word can start a line
  bool correct = this->canStart(vLine.front());
  // if(!correct) return true;

  // test if a word can end a line 
  correct = this->canFinish(vLine.back());
  // if(!correct) return true;

  // iterate to check all lexemes
  correct = this->canFollow(vLine);

  // if(!correct) return true;

  return false;
}

bool SyntaxicAnalyzer::analyze(vector<Lexeme*> vLexemes, bool verbose)
{
  int line = 1;
  vector<Lexeme*> vLine; 
  this->setVerbose(verbose);

  for(auto lexeme : vLexemes) {
    if(line != lexeme->getLine()) {
      line++;
      bool error = this->checkSyntax(vLine);
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

bool SyntaxicAnalyzer::canStart(Lexeme* lex)
{
  /* check if first term can be a starting word */
  string type = lex->typeToString(lex->getType());
  string keyword = lex->getKeyword();
  bool correct = true;

  if(type == "Keyword" && keyword == "else") {
  	if(this->verbose) cout << "   /!\\ ERROR : else is not a valid starting instruction" << endl;
   	correct = false; 
  } else if (type == "Operator") {
  	if(this->verbose) cout << "   /!\\ ERROR : cannot start with operator" << endl;
    correct = false;
  } else {
  	if(this->verbose) cout << "   " + keyword + " is a valid starting instruction" << endl;
  }

  return correct;
}

bool SyntaxicAnalyzer::canFinish(Lexeme* lex)
{
  /* check if first term can be an ending word */
  string type = lex->typeToString(lex->getType());
  string keyword = lex->getKeyword();
  bool correct = true;

  if(type == "Keyword" && (keyword != "true" && keyword != "false")) {
  	if(this->verbose) cout << "   /!\\ ERROR : this keyword is not a valid ending instruction" << endl;
   	correct = false; 
  } else if (type == "Operator") {
  	if(this->verbose) cout << "   /!\\ ERROR : cannot end with operator" << endl;
    correct = false;
  } else if (keyword == "(") { // TODO: separate ending and starting delimiters
  	if(this->verbose) cout << "   /!\\ ERROR : ending delimiter is missing" << endl;
    correct = false;
  } else {
  	if(this->verbose) cout << "   " + keyword + " is a valid ending instruction" << endl;
  }

  return correct;
}

void SyntaxicAnalyzer::setvOperation(std::vector<Operation*> vOperation)
{
  this->vOperation = vOperation;
}

void SyntaxicAnalyzer::setVerbose(bool verbose)
{
  this->verbose = verbose;
}