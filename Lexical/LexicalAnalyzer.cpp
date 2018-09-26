#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "LexicalAnalyzer.h"
#include "LexicalUnities.h"

using namespace std;

Lexeme::Lexeme(string word, int line, int position)
{
  this->keyword = word;
  this->line = line;
  this->position = position;
  this->correct = false;
  this->type = Type::Unknown;
}

void LexicalAnalyzer::split(string line, int lineNumber)
{ 
  istringstream str(line);
  int position = 1;

  do {
    string subs;
    str >> subs;

    if(subs != " " && !subs.empty()) {
      auto lex = new Lexeme(subs, lineNumber, position);
      this->vLexemes.push_back(lex);
      position++;
    }
  } while (str);
}

void LexicalAnalyzer::analyze(bool verbose)
{
  if(verbose) {
  	cout << "[*] ";
	  cout << this->vLexemes.size();
	  cout << " Lexical unities found : " << endl;
  }

  // Iterate through lexemes and check validity
  for(int i = 0; i < this->vLexemes.size(); i++) {
    auto lexeme = vLexemes[i];
    this->check(*lexeme);

    // If verbose, display lexeme informations
    if(verbose) {
      cout << lexeme->getType(); 
      cout << lexeme->isCorrect();
      cout << " Lexeme : " << endl;
      // TODO
    }

    // Check if there is an error
    if(!lexeme->isCorrect()) {
      this->error = true;
    }
  }

  // If no error send to syntax analysis (or return to compilation)
}

void LexicalAnalyzer::check(Lexeme &lexeme)
{
  string keyword = lexeme.getKeyword();

  for(auto key : sKeyword) {
    if(keyword == key) {
      lexeme.setCorrect(true);
      lexeme.setType(Type::Keyword);
      break;
    }
  }

  for(auto op : sOperator) {
    if(keyword == op) {
      lexeme.setCorrect(true);
      lexeme.setType(Type::Operator);
      break;
    }
  }   
  
  // TODO : check numeric and indentificator
}

int Lexeme::getLine() { return this->line; }
int Lexeme::getPosition() { return this->position; }
bool Lexeme::isCorrect() { return this->correct; }
string Lexeme::getKeyword() { return this->keyword; }
Type Lexeme::getType() { return this->type; }

void Lexeme::setCorrect( bool correct) { this->correct = correct; }
void Lexeme::setType(Type type) { this->type = type; }