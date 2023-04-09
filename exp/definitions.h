#pragma once
#include <utility>

using AtributeValue = int;
using Priority = int;
using Token_name = int;
using Token_type = 
    enum : int
    {
        endExpression,
        leftParen,
        rightParen,
        unaryOp,
        binaryOp,
        operand,
        number
    };

using Token = std::pair<Token_name,AtributeValue>;
