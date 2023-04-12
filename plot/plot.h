#include <vector>
#include <string>

class Plot
{
    void showTable(std::vector<double> &fn_results) ;
    void expressionWindow(std::string &expression, int &numTrapz, int &precision, double &start, double &end);
};
