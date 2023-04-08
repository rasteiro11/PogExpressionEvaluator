#pragma once
#include "../lexicon/ilexicon.hpp"
#include "itoken.hpp"
#include "itoken_record.hpp"
#include "token_record.hpp"
#include <iostream>
#include <list>
#include <map>

class Token : public IToken {
public:
  Token(const std::string &identifier, ILexicon *lexicon);
  TokenType kind() const override;
  int priority() const override;
  double value() const override;
  std::string name() const override;
  int code_number() const override;
  void set_parameters();

private:
  int code;
  ILexicon *symbol_table;
  // static std::list<int> parameters;
};
