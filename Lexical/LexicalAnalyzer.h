#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <fstream>
#include <vector>

class Lexeme
{
  public:
    int position;
    bool correct;
    std::string type;
    std::string keyword;

    Lexeme(std::string, int position);
    bool isCorrect();
    void setCorrect();
    void display();
};

class LexicalAnalyzer
{
  private:
    std::vector<std::string> split(std::string line);

  public:
    bool error = false;
    std::vector<Lexeme> vLexeme;

    // TODO : grammar
    void analyze(std::string line, int lineNumber);

	// check if each word is a correct lexical unity defined in LexicalUnities.h

	// for each line display information with line number on lexical untity found or error

	// if there is no error relay to syntaxic analysis
};

#endif 
