#include "exp/expression.h"
#include "exp/token.h"
#include <array>
#include <string>
#include <iostream>

int main()
{
    std::string str_expr = "sin x*x^3+2*x;";
    std::cout << "\nExpression at the start\n";
    std::cout << str_expr << '\n';
    if(addSpaces(str_expr) == false)
    {
        std::cout << "\nExpression after whitespaces are added\n";
        std::cout << str_expr << '\n';
        //int i = 0;
        //for (auto pog : str_expr)
        //{
        //    std::cout << pog << " : " << i << ';';
        //    i++;
        //}
        
        std::cout << "\nTokenized Expression\n";
        std::array<std::string, 7> pepega = {
            "endExpression",
            "leftParen",
            "rightParen",
            "unaryOp",
            "binaryOp",
            "operand",
            "number"
        };

        Expression expression(str_expr);
        while (!expression.isEmpty())
        {
            std::cout << pepega[expression.getFirst().first];
            std::cout << " : ";
            std::cout << expression.getFirst().second << '\n';
            expression.removeFirstToken();
        }
    }
    else
        std::cout << "Lexical error in the expression\n";

    return 0;
}

/*
 
        9	:	sin	
        17	:	x
        14	:	*
        17	:	x
        16	:	^
        20	:	number
        12	:	+
        21	:	number
        14	:	*
        17	:	x
        0	:	;
        
        sin x * x ^ 3 + 2 * x
 * */
