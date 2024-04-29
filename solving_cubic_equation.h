#ifndef MATH_MODELING_SOLVING_CUBIC_EQUATION_H
#define MATH_MODELING_SOLVING_CUBIC_EQUATION_H
#include <vector>
#include <complex>

namespace mashkin
{
    void solve_cubic_equation(std::vector< std::complex< double > >& x, double p1, double p2, double p3, double p4, double p5, double p6);
}
#endif
