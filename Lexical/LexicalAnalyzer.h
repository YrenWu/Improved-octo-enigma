#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <fstream>
#include <vector>

class Lexeme
{
  private:
    bool correct;

  public:
    int line;
    int position;
    std::string type;
    std::string keyword;
    Lexeme(std::string, int line, int position);

    bool isCorrect();
    void setCorrect();
    void display();
};

class LexicalAnalyzer
{
  private:
    bool error = false;
    std::vector<Lexeme*> vLexemes;

  public:
    // TODO : grammar
    void analyze(bool verbose);
    void split(std::string line, int lineNumber);

	// check if each word is a correct lexical unity defined in LexicalUnities.h

	// for each line display information with line number on lexical untity found or error

	// if there is no error relay to syntaxic analysis
};

#endif 
