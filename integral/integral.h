#include "../exp/expression.h"
#include <utility>
#include <vector>

struct TrapezoidIntegral
{
    int nOfTrapz;
    int precision;
    double errorRounding;
    double sumTraps;
    double x_start, x_end;
    void calculateIntegral(Expression &expr,std::vector<std::pair<double, double>> &fnTable);
    TrapezoidIntegral() = default;
    TrapezoidIntegral(double start, double end, int num, int precision);
};
