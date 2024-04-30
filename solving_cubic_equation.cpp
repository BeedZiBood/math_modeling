#include "solving_cubic_equation.h"
#include "comparison_between_doubles.h"
#include <iostream>
#include <cmath>
#include <numbers>

namespace mashkin
{
    void solve_cubic_equation(std::vector< std::complex< double > >& x, std::complex< double > a, std::complex< double > b, std::complex< double > c, std::complex< double > d)
    {
        using namespace std::complex_literals;
        std::complex< double > p = (a * c * 3.0 - b * b) / (a * a * 3.0);
        std::complex< double > q = (2.0 * std::pow(b, 3) - 9.0 * a * b * c + 27.0 * a * a * d) / (27.0 * std::pow(a, 3));
        std::complex< double > Q = std::pow(p / 3.0, 3) + std::pow(q / 2.0, 2);
        if (isDefinitelyGreaterThan(Q.real(), 0.0))
        {
            std::complex< double > alf = std::pow(- q / 2.0 + std::sqrt(Q), 1.0 / 3.0);
            std::complex< double > bet = std::pow(- q / 2.0 - std::sqrt(Q), 1.0 / 3.0);
            std::complex< double > y1 = alf + bet;
            std::complex< double > y2 = -(alf + bet) / 2.0;
            y2.imag(((alf - bet) / 2.0 * std::sqrt(3)).real());
            std::complex< double > y3 = -(alf + bet) / 2.0;
            y3.imag(((-alf - bet) / 2.0 * std::sqrt(3)).real());
            x[0] = y1;
            x[1] = y2;
            x[2] = y3;
        }
        else if (isDefinitelyLessThan(Q.real(), 0.0))
        {
            std::complex< double > y[3]{0};
            for (size_t i = 0; i < 3; i++)
            {
                std::complex< double > first_var = std::sqrt(-p / 3.0);
                std::complex< double > second_var = std::sqrt(-3.0 / p);
                std::complex< double > thrid_var = std::acos((3.0 * q) / (2.0 * p) * second_var);
                std::complex< double > fourth_var = std::cos(thrid_var / 3.0 - static_cast< double >(i) * 2 * std::numbers::pi_v<double> / 3);
                y[i] = 2.0 * first_var * fourth_var;
                std::complex< double > fifth_var = b / (3.0 * a);
                x[i] = y[i] - fifth_var;
            }
        }
        else
        {
            std::complex< double > alf = std::pow(- q / 2.0, 1.0 / 3.0);
            std::complex< double > bet = alf;
            std::complex< double > y1 = alf + bet;
            std::complex< double > y23 = -(alf + bet) / 2.0;
            x[0] = y1 - b / (3.0 * a);
            x[1] = y23 - b / (3.0 * a);
            x[2] = x[1];
        }
    }
}