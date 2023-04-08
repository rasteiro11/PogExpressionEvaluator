#pragma once

#include "expression.hpp"
#include "../token/token.hpp"
#include "../value/value.hpp"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <map>
#include <stack>
#include <sys/types.h>
#include <vector>

class Expression : public IExpression {
private:
  std::vector<IToken> terms;
  int current_term;

public:
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

  ErrorCode get_token(IToken &result) override {
    int nTokens = this->terms.size();
    if (current_term > (nTokens - 1)) {
      return FAILED;
    }
    result = this->terms[current_term++];
    return SUCCESS;
  };

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
            else if (prior.priority() < curr.priority())
              endRight = true;
            else if (curr.priority() == 6)
              endRight = true;
            else
              ans.put_token(prior);
            if (!endRight)
              delayedOps.push(curr);
          }
        } while (!endRight);
        delayedOps.push(curr);
        break;
      }
    }
    while (!delayedOps.empty()) {
      prior = delayedOps.top();
      ans.put_token(prior);
      delayedOps.pop();
    }
    // WHAT THE FUCK: ans.put_token(";");
    return ans;
  };

  ErrorCode valid_infix() override {
    IToken curr;
    bool leading = true;
    int paren_count = 0;
    while (this->get_token(curr) != FAILED) {
      TokenType type = curr.kind();
      if (type == RIGHTPAREN || type == BINARYOP || type == RIGHTPAREN) {
        if (leading)
          return FAILED;
      } else if (!leading)
        return FAILED;
      if (type == LEFTPAREN)
        paren_count++;
      else if (type == RIGHTPAREN) {
        paren_count--;
        if (paren_count < 0) {
          return FAILED;
        }
      }
      if (type == BINARYOP || type == UNARYOP || type == LEFTPAREN)
        leading = true;
      else
        leading = false;
    }
    if (leading || (paren_count > 0))
      return FAILED;
    // ????????????
    // this->rewind();
    return SUCCESS;
  }

  Value do_binary(const IToken &operation, const Value &first_argument,
                  const Value &second_argument) override {
    switch (operation.code_number()) {
    case 17:
      return first_argument + second_argument;
    case 18:
      return first_argument - second_argument;
    case 19:
      return first_argument * second_argument;
    case 20:
      return first_argument / second_argument;
    case 21:
      return first_argument ^ second_argument;
    }
  }

  void read() override {
    std::string input, word;
    int term_count = 0;
    int x;
    std::cin >> input;
    // GHOST CODE
    // add_spaces(input)
  }
};
