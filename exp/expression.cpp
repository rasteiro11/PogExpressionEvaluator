#include <string>
#include <iostream>
#include <utility>
#include "definitions.h"
#include "expression.h"

//
//using errorHandler = void (*)(std::string errorMesage);
//
//void error(std::string errorMesage)
//{
//    std::cout << errorMesage;
//}
//
//errorHandler addSpaces(std::string &expression)
//{
//    if(true)    
//        return error;
//    else
//        return nullptr;
//}
//
/*This is Autistic as fuck*/


inline bool isAlphabetLexeme(std::string &lexeme)
{
   return lexeme == "x" || lexeme == "e" || lexeme == "pi" ||
          lexeme == "sin" || lexeme == "cos" || lexeme == "exp" ||
          lexeme == "ln" || lexeme == "lg" || lexeme == "abs" ||
          lexeme == "sqrt" || lexeme == "arctan";
}

ErrorCode addSpaces(std::string &expression)
{
    ErrorCode lexicalError = false;
    std::string spacedExpression, auxStr;
    std::string opLexemes = ";()+-*/^";
    auto iteratorString = expression.begin();

    while (iteratorString != expression.end() && !lexicalError)
    {
        if(*iteratorString == ' ')
            iteratorString++;
        else if(*iteratorString >= 'a' && *iteratorString <= 'z')
        {
            do
            {
                auxStr += *iteratorString;                
                iteratorString++;
            }while (*iteratorString >= 'a' && *iteratorString <= 'z');

            if(isAlphabetLexeme(auxStr))
                spacedExpression += auxStr + ' ';
            else 
                lexicalError = true;
            auxStr.clear();
        }
        else if(*iteratorString >= '1' && *iteratorString <= '9')
        {
            do
            {
                auxStr += *iteratorString;                
                iteratorString++;
            }while (*iteratorString >= '0' && *iteratorString <= '9');
            spacedExpression += auxStr + ' ';
            auxStr.clear();

            /* check for float expression */
            /* 3.8*x^3.35  */
        }
        else
        {
            auto auxIterator = opLexemes.begin();
            while (*auxIterator != *iteratorString && auxIterator != opLexemes.end())
                auxIterator++;
            if(auxIterator == opLexemes.end())
            {
                lexicalError = true;
                std::cout << "Error with operation\n";
                std::cout << *iteratorString << '\n';
            }
            else
            {
                spacedExpression += *iteratorString;
                if(*iteratorString == ';')
                    iteratorString = expression.end();
                else
                {
                    iteratorString++;
                    spacedExpression += ' ';
                }
            }
        }
    }

    expression.clear();
    expression = spacedExpression;

    return lexicalError;
}

Expression::Expression(std::string &expression)
{
    symbol_table.setStandardTokens();
    tokenizeExpression(expression);
}

void Expression::tokenizeExpression(std::string &expression)
{
    auto iteratorExpr = expression.begin();
    std::string auxStr;
    AtributeValue token_id;
    bool leading = true;
    Token new_token;
    while(iteratorExpr != expression.end())
    {
        if(*iteratorExpr == ' ')
            iteratorExpr++;

        do
        {
            auxStr += *iteratorExpr;             
            iteratorExpr++;
        }while(*iteratorExpr != ' ' && iteratorExpr != expression.end());

        //std::cout << auxStr << '\n';
        //std::cout << auxStr[0] << '\n';
        //if(iteratorExpr == expression.end())
        //    std::cout << "Iterator got to the end\n";

        if(auxStr[0] >= 'a' && auxStr[0] <= 'z')
        {
            if(auxStr == "x")
                new_token.first = operand;
            else if (auxStr == "e" || auxStr == "pi")
                new_token.first = number;
            else
                new_token.first = unaryOp;
        }
        else if(auxStr[0] >= '0' && auxStr[0] <= '9')
            new_token.first = number;
        else 
        {
            if(auxStr == "(")
                new_token.first = leftParen;
            else if(auxStr == ")")
                new_token.first = rightParen;
            else if(auxStr == ";")
            {
                new_token.first = endExpression;
                //iteratorExpr = expression.end();
            }
            else
                new_token.first = binaryOp;
        }
        
        token_id = symbol_table.findAtribute(auxStr);
        if(token_id == NON_EXISTENT)
        {
            //std::cout << "float -> " << auxStr << '\n';
            float value = std::stof(auxStr);
            token_id = symbol_table.newToken(new Token_data(auxStr,value,0));
        }
        auxStr.clear();
        new_token.second = token_id;
        addToken(new_token);
    }
}

bool Expression::infixToPostfix()
{
    /*Stub*/
    return true;
}

float Expression::evaluateAt(float x)
{
    /*Stub*/
    return 0.0f;
}

void Expression::addToken(Token &new_token)
{
    tokenized_expr.push(new_token);
}

void Expression::removeFirstToken()
{
    tokenized_expr.pop();
}

bool Expression::isValid()
{
    /*Stub*/
    return true;
}

Token Expression::getFirst()
{
    return tokenized_expr.front();
}

bool Expression::isEmpty()
{
    return tokenized_expr.empty();
}

//int main()
//{
//    std::string expr = "lg x +3*x^7 - arctan(cos x*pi*e)+sqrt x*exp x+abs x;";
//    // "sin(x^2+3*x) + cos x*x^2"
//    std::cout << "Before adding spaces\n";
//    std::cout << expr << '\n';
//    if(addSpaces(expr) == false)
//    {
//        std::cout << "After adding spaces\n";
//        std::cout << expr << '\n';
//    }
//    else
//    {
//        std::cout << "Lexical Error in the Expression\n";
//    }
//
//    return 0;
//}

/*
 * if is an operand put whitespace in front
 * 
 * (-b+sqrt(b^2-4*a*c))/4*a*c;
 * ( - b + sqrt ( b ^ 2 - 4 * a * c ) ) / 4 * a * c ;
 * */
