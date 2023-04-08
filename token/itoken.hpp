#pragma once

#include "token_type.hpp"
#include <iostream>

class IToken {
public:
  virtual TokenType kind() const = 0;
  virtual int priority() const = 0;
  virtual double value() const = 0;
  virtual std::string name() const = 0;
  virtual int code_number() const = 0;
};
