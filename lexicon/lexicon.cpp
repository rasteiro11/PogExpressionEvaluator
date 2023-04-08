#include "lexicon.hpp"
#include "../token/token.hpp"
#include "../token/token_record.hpp"
#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string.h>
#include <vector>

Lexicon::Lexicon() {
  std::cout << "BUILDING LEXICON" << std::endl;
  this->count = 0;
  this->index_code = std::map<std::string, int>();
  this->token_data = std::map<int, ITokenRecord *>();
  this->set_standard_tokens();
}

const ITokenRecord *Lexicon::get_token_record(int index_code) {
  if (this->token_data.find(index_code) == this->token_data.end()) {
    std::cout << "[lexicon.get_token_record] this token is not registered in "
                 "lexicon"
              << std::endl;
    return nullptr;
  }

  return this->token_data[index_code];
}

const void Lexicon::add_symbol(const std::string &identifier,
                               ITokenRecord *record) {
  if (this->index_code.find(identifier) == this->index_code.end()) {
    this->index_code[identifier] = this->count;
    this->token_data[this->count] = record;
    this->count++;
  }
}

void Lexicon::set_standard_tokens() {
  int i = 0;
  std::vector<std::string> list;
  const char delim = ' ';
  std::string symbols = "; ( ) ~ abs sqr sqrt exp ln sin cos arctan round "
                        "trunc + - * / ^ x pi e ";
  std::stringstream stream(symbols);
  std::string s;
  while (std::getline(stream, s, delim)) {
    list.push_back(s);
  }
  std::cout << "SETTING STANDARD TOKENS" << std::endl;
  for (auto &i : list) {
    new Token(i, this);
  }
}
