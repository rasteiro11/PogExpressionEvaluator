#include "integral.h"
#include <cmath>
#include <math.h>
#include <utility>
#include <vector>

void setNumber(int precision, double &value);

TrapezoidIntegral::TrapezoidIntegral(double start, double end, int num, int precision)
{
    x_start = start;
    x_end = end;
    nOfTrapz = num;
    this->precision = precision;
}

void TrapezoidIntegral::calculateIntegral(Expression &expr, std::vector<std::pair<double, double>> &fnTable)
{
    double increment = std::abs(x_end - x_start) / static_cast<double>(nOfTrapz);
    double x = x_start;
    double f_late, f_early;
    fnTable.clear();
    sumTraps = 0.0F;

    expr.evaluateAt(x, f_late);
    setNumber(precision,f_late);
    fnTable.push_back(std::pair<double, double>(x, f_late));
    x += increment;
    expr.evaluateAt(x, f_early);
    setNumber(precision, f_early);

    for (int i = 1; i <= nOfTrapz; i++)
    {
        fnTable.push_back(std::pair<double, double>(x, f_early));
        x += increment;
        sumTraps += increment * (f_early + f_late) / 2.0F;
        f_late = f_early;
        expr.evaluateAt(x, f_early);
        setNumber(precision, f_early);
    }    

    errorRounding = nOfTrapz * (5.0F / std::pow(10.0F, precision + 1)) * increment;
}

void setNumber(int precision, double &value)
{
    value *= pow(10.0, precision);
    value = std::round(value);
    value /= pow(10.0, precision);
}
