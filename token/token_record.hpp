#pragma once
#include "../lexicon/ilexicon.hpp"
#include "./itoken_record.hpp"
#include <string>

class TokenRecord : public ITokenRecord {
public:
  TokenRecord();
  TokenRecord(const char *, TokenType type, double value);
  TokenType kind() const override;
  std::string name() const override;
  double value() const override;

private:
  int code;
  std::string n;
  int priority;
  double v;
  TokenType k;
};
