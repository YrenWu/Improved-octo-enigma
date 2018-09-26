#ifndef LEXICAL_ANALYZER_H
#define LEXICAL_ANALYZER_H

#include <iostream>
#include <vector>

enum Type {
  Operator, Identificator, Keyword, Numeric, Unknown
};

std::string typeToString(Type type);

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
};

class LexicalAnalyzer
{
  private:
    bool error = false;
    std::vector<Lexeme*> vLexemes;

    void validate(Lexeme &lexeme, Type type);
    void check(Lexeme &lexeme);

  public:
    bool analyze(bool verbose);
    void split(std::string line, int lineNumber);
};

#endif 
