#include <queue>
#include <list>
#include <map>
#include <string>
#include <utility>
#include "definitions.h"
#include "lexicon.h"

using ErrorCode = bool;

class Expression
{
    std::list<Token> tokenized_expr;
    Lexicon symbol_table;
    public:
        Expression() = default;
        Expression(std::string &expression); //Tokenize the expression
        ErrorCode infixToPostfix(); //certify that expression is valid first
        float evaluateAt(float x);
        void tokenizeExpression(std::string &expression);
        void getIteratorRange(std::list<Token>::iterator &start,
                              std::list<Token>::iterator &end); //comment later
        ErrorCode isValid();     //check for infix
    private:
        void removeFirstToken(); //move back to private
        void addToken(Token &new_token);
};

/*Autenticate lexical correctness of expression before sending to the class*/
/*Also add whitespace to better identify lexemes*/
ErrorCode addSpaces(std::string &expression);
