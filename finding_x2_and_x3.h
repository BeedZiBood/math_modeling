#ifndef MATH_MODELING_FINDING_X2_AND_X3_H
#define MATH_MODELING_FINDING_X2_AND_X3_H
#include <vector>
#include <complex>

namespace mashkin
{
    void find_x2(std::vector< std::complex< double > >& x1, std::vector< std::complex< double > >& x2, double p1, double p2, double p4);
    void find_x3(std::vector< std::complex< double > >& x1, std::vector< std::complex< double > >& x3, double p4);
}
#endif
