#pragma once
#include "./lexicon.hpp"
#include <cstdlib>

class Lexicon : public ILexicon {
public:
  Lexicon() {
    this->index_code = new int[hash_size];
    this->count = 0;
    for (int i = 0; i < this->hash_size; i++) {
      this->index_code[i] = -1;
    }
    this->set_standard_tokens();
  }

  int *get_count() override { return &this->count; };
  int *get_index_code() override { return this->index_code; };

  void set_standard_tokens() override { int i = 0; }

private:
  int count;
  int hash_size;
  int *index_code;
};
