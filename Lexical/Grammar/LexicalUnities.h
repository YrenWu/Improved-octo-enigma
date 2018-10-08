#ifndef LEXICAL_UNITIES_H
#define LEXICAL_UNITIES_H

#include <regex>
#include <set>

/* 
  For now instructions block are only on a single line, 
  just parenthesis as delimiters for conditions.
  */

std::set<std::string> sKeyword = {
  { "while" },
  { "if" },
  { "else" },
  { "print" },
  { "scan" },
  { "true" },
  { "false" }
};

std::set<std::string> sOperator = {
  { "==" },
  { "!=" },
  { "<" },
  { "<=" },
  { "*" },
  { "+" },
  { ">=" },
  { ">" },
  { "/" },
  { "-" },
  { "=" },
  { "&&" },
  { "||" }
};

/* Match delimiters TODO: { } ; [ ] */
std::regex const rDelimiters { R"(^\(|\))" };

/* Match numbers */
std::regex const rNumbers { R"(^[-+]?\d+\.?\d*$)" };

/* Match alphanumeric strings */
std::regex const rIdentificators { R"(\w+)" };

#endif
