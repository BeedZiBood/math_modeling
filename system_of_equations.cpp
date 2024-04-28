#include "sustem_of_equations.h"
#include <cmath>

namespace mashkin
{
    double calc_x1(double x, double p1, double p2, double p3, double p4, double p5, double p6)
    {
        return -std::pow(x, 3) * p2 - std::pow(x, 2) * (p1 * p2 + p4 * (p2 * p3 + p5 + p2) + p5 - 1) - x * (p4 * (p1 * p2 + p3 * p6 - p3 - p2 * p3 * p4 - p1 * p6) - p1 - p1 * p2) + p4 * p3 * p6;
    }
}