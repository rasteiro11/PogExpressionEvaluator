#pragma once
#include "../token/token.hpp"
#include <string>

class ITokenRecord {
public:
  virtual TokenType kind() const;
  virtual std::string name() const;
  virtual double value() const;
};
