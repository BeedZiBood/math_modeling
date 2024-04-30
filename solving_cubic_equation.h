#ifndef MATH_MODELING_SOLVING_CUBIC_EQUATION_H
#define MATH_MODELING_SOLVING_CUBIC_EQUATION_H
#include <vector>
#include <complex>

namespace mashkin
{
    void solve_cubic_equation(std::vector< std::complex< double > >& x, std::complex< double > a, std::complex< double > b, std::complex< double > c, std::complex< double > d);
}
#endif
