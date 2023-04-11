#include "../exp/expression.h"
#include <vector>
#include <iomanip>

struct TrapezoidIntegral
{
    int nOfTraps;
    int precision;
    double errorRounding;
    double sumTraps;
    double x_start, x_end;
    void calculateIntegral(Expression &expr,std::vector<double> &fnTable);
    TrapezoidIntegral() = default;
    TrapezoidIntegral(double start, double end, int num, int precision);
};
