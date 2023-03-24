#pragma once

enum TokenType { OPERAND, UNARYOP, BINARYOP, LEFTPAREN, RIGHTPAREN, EOE };

class IToken {
public:
  virtual TokenType kind();
};
