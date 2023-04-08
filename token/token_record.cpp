#include "token_record.hpp"
#include "../lexicon/lexicon.hpp"
#include "token.hpp"
#include <iostream>

TokenRecord::TokenRecord() {}

TokenRecord::TokenRecord(const char *name, TokenType type, double value) {
  this->n = name;
  this->k = type;
  this->v = value;
}

TokenType TokenRecord::kind() const { return this->k; }

std::string TokenRecord::name() const { return this->n; }

double TokenRecord::value() const { return this->v; }
