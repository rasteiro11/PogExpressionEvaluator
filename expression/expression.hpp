#pragma once

#include "../error/error.hpp"
#include "../token/token.hpp"
#include "../value/value.hpp"

class IExpression {
public:
  virtual ErrorCode eval_prefix(Value &result);
  virtual ErrorCode eval_postfix(Value &result);
  virtual ErrorCode get_token(IToken &result);
  virtual Value do_unary(const IToken &operation, const Value &the_argument);
  virtual Value do_binary(const IToken &operation, const Value &first_argument,
                          const Value &second_argument);
  virtual Value get_value(const IToken &operand);
  virtual IExpression infix_to_postfix();
  virtual void put_token(const IToken &t);
  virtual void read();
  virtual ErrorCode valid_infix();
};
