#include "exp/expression.h"
#include "exp/token.h"
#include "integral/integral.h"
#include <ios>
#include <ostream>
#include <string>
#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#include <iomanip>

int main() {
    bool quit = false;
    bool cannot_be_conv = false;
    std::string user_expr;
    std::string user_info1, user_info2;
    int numTrapz, precision;
    double start, end;
    std::vector<std::pair<double, double>> fnTable;

    Expression *expression;
    do
    {
        std::cout << "\nEscreva uma expressao:\n";
        std::cout << "f(x) = ";
        std::getline(std::cin, user_expr);
        user_expr += ';';
        std::endl(std::cout);

        if(!addSpaces(user_expr))
        {
            expression = new Expression(user_expr);
            if(expression->isValid())
            {
                expression->infixToPostfix();
                do{
                    std::cout << "\nEscreva o ponto extremo da esquerda:\n";
                    std::cin >> user_info1; 
                    std::cout << "Escreva o ponto extremo da direita:\n";
                    std::cin >> user_info2; 
                    try{
                        start = std::stold(user_info1.data()); 
                        end = std::stold(user_info2.data()); 
                        cannot_be_conv = false;
                        user_info1.clear(), user_info2.clear();
                    }catch (std::invalid_argument){
                        std::cout << "Uma variavel foi escrita de forma indevida";
                        cannot_be_conv = true;                    
                    }
                }while (cannot_be_conv);

                do {
                    std::cout << "\nEscreva o numero de casas decimais\n"; 
                    std::cin >> user_info1; 
                    std::cout << "Escreva o numero de trapezios:\n";
                    std::cin >> user_info2; 
                    try {
                        precision = std::stoi(user_info1.data());
                        numTrapz = std::stoi(user_info2.data());
                        cannot_be_conv = false;                    
                        user_info1.clear(), user_info2.clear();
                    } catch (std::invalid_argument) {
                        std::cout << "Uma variavel foi escrita de forma indevida";
                        cannot_be_conv = true;
                    }
                }while (cannot_be_conv);

                std::cout << std::fixed;
                std::cout << std::setprecision(precision + 1);
                
                TrapezoidIntegral integralCalc(start,end,numTrapz,precision);
                integralCalc.calculateIntegral(*expression, fnTable);

                std::cout << "\n\nSaida:\n\n";
                std::cout << "Erro de arredondamento = " << integralCalc.errorRounding;

                std::cout << std::fixed;
                std::cout << std::setprecision(precision);

                std::cout << "\nValor da Integral = " << integralCalc.sumTraps;
                std::cout << "\nTabela de Valores:\n";
                std::cout << 'x'; 

                for (int i = -1; i <= precision; i++)
                    std::cout << ' ';

                std::cout << "| " << "f(x)" << '\n';
                for (auto f : fnTable)
                    std::cout << f.first << " | " << f.second << '\n';
                delete expression;
            }
            else
                std::cout << "\nA expressao fornecida contem erro\n";
        }
        else
            std::cout << "\nErro Lexico detectado na expressao fornecida\n";

        std::cout << "Deseja sair do programa?\n";
        std::cout << "Sim (Escreva q)\t Nao (Escreva qualquer coisa)\n";
        std::cin >> user_info1;
        if(user_info1 == "q")
            quit = true;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        user_expr.clear();
        user_info1.clear(); 
        std::cout << "\033[2J\033[1;1H";

    }while (!quit); 
    return 0;
}
