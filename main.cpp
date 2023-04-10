#include "exp/expression.h"
#include "exp/token.h"
#include <array>
#include <cmath>
#include <list>
#include <string>
#include <iostream>

int main()
{
    std::string str_expr = "-sin x*x^30+23*(+x);";
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
        std::list<Token>::iterator start, end;
        expression.getIteratorRange(start, end);
        while (start != end)
        {
            std::cout << pepega[start->first];
            std::cout << " : ";
            std::cout << start->second << '\n';
            start++;
        }

        if(expression.isValid())
        {
            std::cout << "\nExpression is Valid\n";
            expression.infixToPostfix();
            expression.getIteratorRange(start, end);
            while (start != end)
            {
                std::cout << pepega[start->first];
                std::cout << " : ";
                std::cout << start->second << '\n';
                start++;
            }
            float f_of_x;
            if(expression.evaluateAt(M_PI, f_of_x))
                std::cout << "f(pi) = " << f_of_x << '\n';
            else
                std::cout << "FAZ O L\n";
        }
        else
            std::cout << "\nExpression is Invalid\n";
    }
    else
        std::cout << "Lexical error in the expression\n";

    return 0;
}

/*
        3   :   ~
        9	:	sin	
        17	:	x
        14	:	*
        17	:	x
        16	:	^
        20	:	number
        12	:	+
        21	:	number
        14	:	*
        1   :   (
        17	:	x
        2   :   )
        0	:	;
        
        - sin x * x ^ 3 + 2 * ( + x )
 * */
