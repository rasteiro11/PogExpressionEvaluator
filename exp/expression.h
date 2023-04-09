#include <queue>
#include <map>
#include <string>
#include <utility>
#include "definitions.h"
#include "lexicon.h"

class Expression
{
    std::queue<Token> tokenized_expr;
    Lexicon symbol_table;
    public:
        Expression() = default;
        Expression(std::string &expression); //Tokenize the expression
        bool infixToPostfix(); //certify that expression is valid first
        float evaluateAt(float x);
        void tokenizeExpression(std::string &expression);
        Token getFirst();       //comment later
        bool isEmpty();       //comment later
        void removeFirstToken(); //move back to private
    private:
        void addToken(Token &new_token);
        bool isValid();     //check for infix
};
