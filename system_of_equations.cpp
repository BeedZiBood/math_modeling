#include "system_of_equations.h"
#include <cmath>

namespace mashkin
{
    double calc_x1(double x1, double p1, double p2, double p3, double p4, double p5, double p6)
    {
        double x2 = calc_x2(x1, p1, p2, p4);
        double x3 = calc_x3(x1, p4);
        return (-p1 * x2 - x1 * x2 + p5 * x3) / p3 + p4 * (p6 - x2);
    }

    double calc_x2(double x1, double p1, double p2, double p4)
    {
        return (p2 * p4 * x1 - x1 + x1 * x1) / (p1 - x1);
    }

    double calc_x3(double x1, double p4)
    {
        return x1 / (1 + p4);
    }
}