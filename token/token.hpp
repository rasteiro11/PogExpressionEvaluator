#pragma once
#include <iostream>

enum TokenType { OPERAND, UNARYOP, BINARYOP, LEFTPAREN, RIGHTPAREN, EOE };

class IToken {
public:
  virtual TokenType kind() const;
  virtual int priority() const;
  virtual double value() const;
  virtual std::string name() const;
  virtual int code_number() const;
};
