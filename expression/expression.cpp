#pragma once

#include "expression.hpp"
#include "../token/token.hpp"
#include "../value/value.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <stack>

class Expression : public IExpression {
  ErrorCode eval_prefix(Value &result) override {
    IToken t;
    Value theArg, firstArg, seconArg;

    if (get_token(t) == FAILED)
      return FAILED;

    switch (t.kind()) {
    case UNARYOP:
      if (eval_prefix(theArg) == FAILED) {
        return FAILED;
      }

      result = do_unary(t, theArg);
      break;
    case BINARYOP:
      if ((eval_prefix(theArg) == FAILED) ||
          (eval_prefix(seconArg) == FAILED)) {
        return FAILED;
      }

      result = do_binary(t, firstArg, seconArg);
      break;
    case OPERAND:
      result = get_value(t);
      break;
    case EOE:
      break;
    }

    return SUCCESS;
  }

  ErrorCode eval_postfix(Value &result) override {
    IToken t;
    std::stack<Value> operands;
    Value theArg, firstArg, seconArg;
    do {
      if (get_token(t) == FAILED)
        return FAILED;

      switch (t.kind()) {
      case UNARYOP:
        if (operands.empty())
          return FAILED;
        theArg = operands.top();
        operands.pop();
        operands.push(do_unary(t, theArg));
        break;

      case BINARYOP:
        if (operands.empty())
          return FAILED;
        seconArg = operands.top();
        operands.pop();
        if (operands.empty())
          return FAILED;
        firstArg = operands.top();
        operands.pop();
        operands.push(do_binary(t, firstArg, seconArg));
        break;

      case OPERAND:
        operands.push(get_value(t));
        break;

      case EOE:
        break;
      }
    } while (t.kind() != EOE);

    if (operands.empty())
      return FAILED;

    result = operands.top();
    operands.pop();

    if (!operands.empty())
      return FAILED;

    return SUCCESS;
  }

  ErrorCode get_token(IToken &result) override { return FAILED; };

  IExpression infix_to_postfix() override {
    Expression ans;
    IToken curr, prior;

    std::stack<IToken> delayedOps;

    while (get_token(curr) != FAILED) {
      switch (curr.kind()) {
      case OPERAND:
        ans.put_token(curr);
        break;

      case LEFTPAREN:
        delayedOps.push(curr);
        break;

      case RIGHTPAREN:
        prior = delayedOps.top();
        while (prior.kind() != LEFTPAREN) {
          ans.put_token(prior);
          delayedOps.pop();
          prior = delayedOps.top();
        }
        delayedOps.top();
        break;
      case UNARYOP:
      case BINARYOP:
        bool endRight = false;
        do {
          if (delayedOps.empty())
            endRight = true;
          else {
            prior = delayedOps.top();
            if (prior.kind() == LEFTPAREN)
              endRight = true;
            else if (prior.priority() < curr.priority()) {
              endRight = true;
            }
          }

        } while (!endRight);
      }
    }
  };
