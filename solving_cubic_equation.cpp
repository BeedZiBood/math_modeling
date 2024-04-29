#include "solving_cubic_equation.h"
#include "comparison_between_doubles.h"
#include <iostream>
#include <cmath>
#include <numbers>

namespace mashkin
{
    void solve_cubic_equation(std::vector< std::complex< double > >& x, double p1, double p2, double p3, double p4, double p5, double p6)
    {
        using namespace std::complex_literals;
        double a = -1 - p4;
        double b = p1 - (p2 * p4) + (p4 * p1) - (p4 * p4 * p2) + p4 + 1 - p5 - (p4 * p3) - (p3 * p4 * p4);
        double c = p1 - (p1 * p2 * p4) - (p4 * p4 * p1 * p2) + (p4 * p1) + (p1 * p5) - (p3 * p4 * p6) - (p3 * p2 * p4 * p4) + (p4 * p3) - (p3 * p4 * p4 * p6) - (p3 * p4 * p4 * p4 * p2) + (p3 * p4 * p4);
        double d = p3 * p4 * p1 * (1 + p4);
        double p = (3 * a * c - b * b) / (3 * a * a);
        double q = (2 * std::pow(b, 3) - 9 * a * b * c + 27 * a * a * d) / (27 * std::pow(a, 3));
        double Q = std::pow(p / 3, 3) + std::pow(q / 2, 2);
        if (isDefinitelyGreaterThan(Q, 0.0))
        {

            double alf = std::cbrt(- q / 2 + std::sqrt(Q));
            double bet = std::cbrt(- q / 2 - std::sqrt(Q));
            double y1 = alf + bet;
            std::complex< double > y2 = -(alf + bet) / 2;
            y2.imag((alf - bet) / 2 * std::sqrt(3));
            std::complex< double > y3 = -(alf + bet) / 2;
            y3.imag((-alf - bet) / 2 * std::sqrt(3));
            x[0] = y1;
            x[1] = y2;
            x[2] = y3;
        }
        else if (isDefinitelyLessThan(Q, 0.0))
        {
            double y[3]{0};
            for (size_t i = 0; i < 3; i++)
            {
                double first_var = std::sqrt(-p / 3.0);
                double second_var = std::sqrt(-3.0 / p);
                double thrid_var = std::acos((3.0 * q) / (2.0 * p) * second_var);
                double fourth_var = std::cos(thrid_var / 3.0 - static_cast< double >(i) * 2 * std::numbers::pi_v<double> / 3);
                std::complex<double> z4 = 1.0 + 2i;
                y[i] = 2 * first_var * fourth_var;
                y[i] = 2 * std::sqrt(-p / 3) * std::cos(1 / 3 * std::acos((3 * q) / (2 * p) * std::sqrt(-3 / p)) - i * 2 * std::numbers::pi_v<double> / 3);
                //std::complex< double > res_y = y[i] - b / (3 * a);
                x[i] = y[i] - b / (3 * a);
            }
        }
        else
        {
            double alf = std::cbrt(- q / 2);
            double bet = alf;
            double y1 = alf + bet;
            double y23 = -(alf + bet) / 2;
            x[0] = y1 - b / (3 * a);
            x[1] = y23 - b / (3 * a);
            x[2] = x[1];
        }
    }
}