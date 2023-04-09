#include <map>
#include <string>
#include <vector>
#include "definitions.h"
#include "token.h"
#define NON_EXISTENT -1

using ErrorCode = bool;

class Lexicon
{
    std::map<std::string, AtributeValue> lexeme_map; //shall only be used to setup expression
    std::vector<Token_data*> symbol_table;
    public:
        Lexicon() = default;
        void setStandardTokens();   //sets up the map to lexemes
        Token_data* getTokenInfo(AtributeValue token_id); 
        AtributeValue newToken(Token_data *new_token);
        AtributeValue findAtribute(std::string &lexeme);
};

/*Autenticate lexical correctness of expression before sending to the class*/
/*Also add whitespace to better identify lexemes*/
ErrorCode addSpaces(std::string &expression);
