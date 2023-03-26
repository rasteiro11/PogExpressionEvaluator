#pragma once

#include "token.hpp"
#include "../lexicon/lexicon.hpp"
#include "token_record.hpp"
#include <iostream>
#include <list>
#include <ostream>

class Token : public IToken {
public:
  TokenType kind() const override {
    return this->symbol_table.get_token_data()[code].kind();
  }

  Token(const std::string &identifier) {
    int location = this->symbol_table.hash(identifier);
    if (this->symbol_table.get_index_code()[location] == -1) {
      // DANGER
      this->code = (*this->symbol_table.get_count())++;
      this->symbol_table.get_token_data()[code] = attributes(identifier);
      if (is_parameter(symbol_table.get_token_data()[code])) {
        parameters.insert(parameters.begin(), this->code);
      } else
        code = this->symbol_table.get_index_code()[location];
    }
  }

  void set_parameters() {
    int n = parameters.size();
    int index_code;
    double x;
    for (auto it = parameters.begin(); it != parameters.end(); it++) {
      index_code = *it;
      ITokenRecord &r = this->symbol_table.get_token_data()[index_code];
      std::cout << "Give a new value for param" << (r.name()).c_str()
                << " with value " << r.value() << std::endl;
      std::cout << "Enter a value or a new line to keep the old value:"
                << std::flush;
      std::cin >> x;
    }
  }

private:
  int code;
  static ILexicon symbol_table;
  static std::list<int> parameters;
};

std::list<int> Token::parameters;
ILexicon Token::symbol_table;
