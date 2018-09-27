#ifndef LEXICAL_UNITIES_H
#define LEXICAL_UNITIES_H

#include <regex>
#include <set>

/* For now instructions block are on a single line, */

std::set<std::string> sKeyword = {
  { "while" },
  { "if" },
  { "else" },
  { "while" },
  { "print" },
  { "scan" },
  { "true" },
  { "false" },
  { "or" },
  { "and" }
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

/* Match numbers */
std::regex const rNumbers { R"(^[-+]?\d+\.?\d*$)" };

/* Match alphanumeric strings */
std::regex const rIdentificators { R"(\w+)" };

#endif
