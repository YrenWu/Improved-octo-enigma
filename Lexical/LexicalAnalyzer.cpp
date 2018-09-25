#include <iostream>
#include <vector>
#include <sstream>
#include <string>

#include "LexicalAnalyzer.h"

using namespace std;

Lexeme::Lexeme(string word, int position)
{
  this->keyword = word;
  this->position = position;
}

vector<std::string> LexicalAnalyzer::split(string line)
{
  vector<std::string> vSplitted;
  istringstream str(line);

  do{
    string subs;
    str >> subs;
    if(subs.compare(" ")) {
      vSplitted.push_back(subs);
    }
  } while (str);
  return vSplitted;
}

void LexicalAnalyzer::analyze(std::string line, int lineNumber)
{
  vector<string> words;
  words = this->split(line);
  for(size_t i = 0; i < words.size(); ++i) {
    // new Lexeme(words[i], lineNumber);
    // TODO check Lexeme validity and populate lexeme vector
  }
}
