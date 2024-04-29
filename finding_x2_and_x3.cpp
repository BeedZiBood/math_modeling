#include "finding_x2_and_x3.h"
#include <cstddef>

namespace mashkin
{
    void find_x3(std::vector< std::complex< double > >& x1, std::vector< std::complex< double > >& x3, double p4)
    {
        for (size_t i = 0; i < 3; i++)
        {
            x3[i] = x1[i] / (1 + p4);
        }
    }

    void find_x2(std::vector< std::complex< double > >& x1, std::vector< std::complex< double > >& x2, double p1, double p2, double p4)
    {
        for (size_t i = 0; i < 3; i++)
        {
            x2[i] = (p2 * p4 * x1[i] - x1[i] + std::pow(x1[i], 2)) / (p1 - x1[i]);
        }
    }
}