#include "../token/itoken_record.hpp"
#include "ilexicon.hpp"
#include <map>

class Lexicon : public ILexicon {
public:
  Lexicon();
  void set_standard_tokens() override;
  const ITokenRecord *get_token_record(int index_code) override;
  const void add_symbol(const std::string &identifier,
                        ITokenRecord *record) override;

private:
  int count;
  std::map<int, ITokenRecord *> token_data;
  std::map<std::string, int> index_code;
};
