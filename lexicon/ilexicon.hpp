#pragma once
#include "../token/itoken_record.hpp"
#include <iostream>

class ILexicon {
public:
  virtual void set_standard_tokens() = 0;
  virtual const ITokenRecord *get_token_record(int index_code) = 0;
  virtual const void add_symbol(const std::string &identifier,
                                ITokenRecord *record) = 0;
};
