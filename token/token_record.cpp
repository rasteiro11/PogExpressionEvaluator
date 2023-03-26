#pragma once
#include "../lexicon/lexicon.hpp"
#include "token.hpp"
#include <iostream>

class TokenRecord : ITokenRecord {
public:
  std::string n;
  int priority;
  double v;
  TokenType k;

  TokenType kind() const override { return this->k; }
  std::string name() const override { return this->n; }
  double value() const override { return this->v; }

private:
  int code;
  static ILexicon symbol_table;
};
