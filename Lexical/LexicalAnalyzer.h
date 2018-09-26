#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <fstream>
#include <vector>

enum Type {
  Operator, Identificator, Keyword, Numeric, Unknown
};

class Lexeme
{
  private:
    bool correct;
    int line;
    int position;
    Type type;
    std::string keyword;

  public:
    void setCorrect(bool correct);
    void setType(Type type);

    bool isCorrect();
    int getLine();
    int getPosition();
    Type getType();
    std::string getKeyword();

    Lexeme(std::string, int line, int position);

    // void display();
};

class LexicalAnalyzer
{
  private:
    bool error = false;
    std::vector<Lexeme*> vLexemes;

    void check(Lexeme &lexeme);

  public:
    void analyze(bool verbose);
    void split(std::string line, int lineNumber);
    
	// check if each word is a correct lexical unity defined in LexicalUnities.h

	// for each line display information with line number on lexical untity found or error

	// if there is no error relay to syntaxic analysis
};

#endif 
