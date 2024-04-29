#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include "finding_x2_and_x3.h"
#include "comparison_between_doubles.h"
#include "solving_cubic_equation.h"

int main() {
    int flag;
    double p1 = 8.4e-6, p2 = 6.6667E-4, p3 = 1.7778E-5, p5 = 2;
    std::vector< std::complex< double > > x1({0, 0, 0});
    std::vector< std::complex< double > > x2({0, 0, 0});
    std::vector< std::complex< double > > x3({0, 0, 0});

    //mashkin::solve_cubic_equation(x1, p1, p2, p3, 10, p5, 10);
    //std::cout << x1[0] << " " << x1[1] << " " << x1[2] << "\n\n";

    for (size_t i = 1; i <= 2; i++)
    {
        double p6 = std::pow(10, i);
        for (size_t j = 0; j < 5;j++)
        {
            int degree = -2 + static_cast< int >(j);
            double h = std::pow(10, degree);
            for (double p4 = h; mashkin::isDefinitelyLessThan(p4, h * 9); p4 += h)
            {
                mashkin::solve_cubic_equation(x1, p1, p2, p3, p4, p5, p6);
                mashkin::find_x2(x1, x2, p1, p2, p4);
                mashkin::find_x3(x1, x3, p4);
                std::cout << p4 << " " << p6 << " " << x1[0] << " " << x1[1] << " " << x1[2] << "\n";
                std::cout << p4 << " " << p6 << " " << x2[0] << " " << x2[1] << " " << x2[2] << "\n";
                std::cout << p4 << " " << p6 << " " << x3[0] << " " << x3[1] << " " << x3[2] << "\n";
                std::cout << "\n";
            }
        }
    }
    return 0;
}