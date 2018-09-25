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
	  cout << this->vLexemes.size();
	  cout << " Lexical unities found : " << endl;
  }
}
