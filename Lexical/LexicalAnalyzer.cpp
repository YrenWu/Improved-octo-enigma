#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "LexicalAnalyzer.h"

using namespace std;

Lexeme::Lexeme(string word, int line, int position)
{
  this->keyword = word;
  this->line = line;
  this->position = position;
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
    //cout << vLexemes[i]->keyword;
	  // check validity and display lexem
	  // TODO check Lexeme validity and populate lexeme vector
  //}
}

int Lexeme::getLine() { return this->line; }
int Lexeme::getPosition() { return this->position; }
std::string Lexeme::getKeyword() { return this->keyword; }
bool Lexeme::isCorrect() { return this->correct; }
void Lexeme::setCorrect( bool correct) { this->correct = correct; }