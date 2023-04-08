#include "token.hpp"
#include "../lexicon/lexicon.hpp"
#include "itoken_record.hpp"
#include "token_record.hpp"
#include <cstdlib>
#include <iostream>
#include <list>
#include <map>
#include <ostream>

static std::map<std::string, ITokenRecord *> lexeme = {
    {";", new TokenRecord(";", EOE, 0)},
    {"(", new TokenRecord("(", LEFTPAREN, 0)},
    {")", new TokenRecord(")", RIGHTPAREN, 0)},
    {"~", new TokenRecord("~", UNARYOP, 6)},
    {"abs", new TokenRecord("abs", UNARYOP, 6)},
    {"sqr", new TokenRecord("sqr", UNARYOP, 6)},
    {"sqrt", new TokenRecord("sqrt", UNARYOP, 6)},
    {"exp", new TokenRecord("exp", UNARYOP, 6)},
    {"ln", new TokenRecord("ln", UNARYOP, 6)},
    {"sin", new TokenRecord("sin", UNARYOP, 6)},
    {"cos", new TokenRecord("cos", UNARYOP, 6)},
    {"arctan", new TokenRecord("arctan", UNARYOP, 6)},
    {"round", new TokenRecord("round", UNARYOP, 6)},
    {"trunc", new TokenRecord("trunc", UNARYOP, 6)},
    {"+", new TokenRecord("+", BINARYOP, 4)},
    {"-", new TokenRecord("-", BINARYOP, 4)},
    {"/", new TokenRecord("/", BINARYOP, 5)},
    {"*", new TokenRecord("*", BINARYOP, 5)},
    {"^", new TokenRecord("^", BINARYOP, 6)},
    {"x", new TokenRecord("x", OPERAND, 0.00000)},
    {"pi", new TokenRecord("pi", OPERAND, 3.14159)},
    {"e", new TokenRecord("e", OPERAND, 2.71828)},
};

bool is_parameter(ITokenRecord &record) {
  if (record.name() == "x") {
    return true;
  }
  return false;
}

TokenType Token::kind() const {
  return this->symbol_table->get_token_record(this->code)->kind();
}

int Token::priority() const {
  return this->symbol_table->get_token_record(this->code)->value();
};

double Token::value() const {
  return this->symbol_table->get_token_record(this->code)->value();
};

std::string Token::name() const {
  return this->symbol_table->get_token_record(this->code)->name();
}

int Token::code_number() const { return this->code; }

// we must have numbers as lexeme
Token::Token(const std::string &identifier, ILexicon *lexicon) {
  this->symbol_table = lexicon;
  if (lexeme.find(identifier) == lexeme.end()) {
    std::cout << "[token.Token] this lexeme " << identifier
              << " is not registered in lexeme list" << std::endl;
    return;
  }

  lexicon->add_symbol(identifier, lexeme[identifier]);
}

void Token::set_parameters() {
  std::cout << "THIS SHIT IS NOT IMPLEMENTED YET STFU" << std::endl;
}
