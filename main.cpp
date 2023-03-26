#include "value/value.hpp"
#include <iostream>

// int main() {
//  IExpression infix, postfix;
//  char c;
//
//  while (c = get_command() != 'q') {
//    do_command(c, infix, postfix);
//  }
//}
//
// void do_command(char c, IExpression &infix, IExpression &postfix) {
//  switch (c) {
//  case 'r':
//    infix.clear();
//    infix.read();
//    if (infix.valid_infix() = SUCCESS)
//      postfix = infix.infix_to_postfix();
//    else
//      std::cout << "Warning: Bad expression ignored" << std::endl;
//    break;
//  case 'w':
//    infix.write();
//    postfix.write();
//    break;
//  case 'p':
//    Token::print_parameters();
//    break;
//  case 'n':
//    Token::set_parameters();
//    break;
//  }
//}
#include <iostream>

int main() {
  std::cout << (Value(69) - Value(9)).val << std::endl;
  std::cout << (Value(2) ^ Value(2)).val << std::endl;
}
