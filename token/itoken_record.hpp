#pragma once
#include "token_type.hpp"
#include <iostream>

class ITokenRecord {
public:
  virtual TokenType kind() const = 0;
  virtual std::string name() const = 0;
  virtual double value() const = 0;
};
