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
      string info = lexeme->isCorrect() ? "" :  "ERROR ";

      info += typeToString(lexeme->getType()) + " lexeme found : " + lexeme->getKeyword();
      info += " on line " + to_string(lexeme->getLine());
      info += " at position " + to_string(lexeme->getPosition());
      cout << info << endl;
    }

    // Check if there is an error
    if(!lexeme->isCorrect()) {
      this->error = true;
    }
  }
}

void LexicalAnalyzer::validate(Lexeme &lexeme, Type type)
{
  lexeme.setCorrect(true);
  lexeme.setType(type);
}

void LexicalAnalyzer::check(Lexeme &lexeme)
{
  string keyword = lexeme.getKeyword();

  for(auto key : sKeyword) {
    if(keyword == key) {
      this->validate(lexeme, Type::Keyword);
      break;
    }
  }

  for(auto op : sOperator) {
    if(keyword == op) {
      this->validate(lexeme, Type::Operator);
      break;
    }
  }   

  bool isNumeric = regex_search(keyword, rNumbers);
  if (isNumeric && !lexeme.isCorrect()) {
    this->validate(lexeme, Type::Numeric);
  }

  bool isIdentificator = regex_search(keyword, rIdentificators);
  if (isIdentificator && !lexeme.isCorrect()) {
    this->validate(lexeme, Type::Identificator);
  }
}

std::string typeToString(Type type) {
  switch(type) {
    case 0:
      return "Operator";
    case 1:
      return "Identificator";
    case 2:
      return "Keyword";
    case 3:
      return "Numeric";
    default:
      return "Unknown";
  }
}

int Lexeme::getLine() { return this->line; }
int Lexeme::getPosition() { return this->position; }
bool Lexeme::isCorrect() { return this->correct; }
string Lexeme::getKeyword() { return this->keyword; }
Type Lexeme::getType() { return this->type; }

void Lexeme::setCorrect( bool correct) { this->correct = correct; }
void Lexeme::setType(Type type) { this->type = type; }
