#pragma once
#include "../token/token_record.hpp"
#include <iostream>

class ILexicon {
public:
  virtual int hash(const std::string &x) const;
  virtual void set_standard_tokens();
  virtual int *get_count();
  virtual int *get_index_code();
  virtual ITokenRecord *get_token_data();
};
