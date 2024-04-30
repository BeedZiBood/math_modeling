#include <iostream>
#include <cmath>
#include <vector>
#include <complex>
#include "finding_x2_and_x3.h"
#include "comparison_between_doubles.h"
#include "solving_cubic_equation.h"
#include "extra_functions_for_course_work.h"

int main() {
    int flag;
    double p1 = 8.4e-6, p2 = 6.6667E-4, p3 = 1.7778E-5, p5 = 2;
    std::vector< std::complex< double > > x1({0, 0, 0});
    std::vector< std::complex< double > > x2({0, 0, 0});
    std::vector< std::complex< double > > x3({0, 0, 0});
    std::vector< std::complex< double > > yacobian_matrix;
    std::vector< std::complex< double > > eigenvalues;
    eigenvalues.resize(3);
    yacobian_matrix.resize(9);

/*
    double a = mashkin::calculate_a_for_x1(10.0);
    double b = mashkin::calculate_b_for_x1(p1, p2, p3, 10.0, p5);
    double c = mashkin::calculate_c_for_x1(p1, p2, p3, 10.0, p5, 10.0);
    double d = mashkin::calculate_d_for_x1(p1, p3, 10.0);

    mashkin::solve_cubic_equation(x1, a, b, c, d);
    std::cout << x1[0] << " " << x1[1] << " " << x1[2] << "\n\n";
*/

    for (size_t i = 1; i <= 2; i++)
    {
        double p6 = std::pow(10, i);
        for (size_t j = 0; j < 5;j++)
        {
            int degree = -2 + static_cast< int >(j);
            double h = std::pow(10, degree);
            for (double p4 = h; mashkin::isDefinitelyLessThan(p4, h * 9); p4 += h)
            {
                double a = mashkin::calculate_a_for_x1(p4);
                double b = mashkin::calculate_b_for_x1(p1, p2, p3, p4, p5);
                double c = mashkin::calculate_c_for_x1(p1, p2, p3, p4, p5, p6);
                double d = mashkin::calculate_d_for_x1(p1, p3, p4);
                mashkin::solve_cubic_equation(x1, a, b, c, d);
                mashkin::find_x2(x1, x2, p1, p2, p4);
                mashkin::find_x3(x1, x3, p4);
                /*std::cout << p4 << " " << p6 << " " << x1[0] << " " << x1[1] << " " << x1[2] << "\n";
                std::cout << p4 << " " << p6 << " " << x2[0] << " " << x2[1] << " " << x2[2] << "\n";
                std::cout << p4 << " " << p6 << " " << x3[0] << " " << x3[1] << " " << x3[2] << "\n";
                std::cout << "\n";*/
                for (size_t k = 0; k < 3; k++)
                {
                    mashkin::calculate_yacobian_matrix(yacobian_matrix, x1[k], x2[k], p1, p2, p3, p4, p5);
                    std::complex< double > a = mashkin::calculate_a_for_jacobian_matrix(yacobian_matrix);
                    std::complex< double > b = mashkin::calculate_b_for_jacobian_matrix(yacobian_matrix);
                    std::complex< double > c = mashkin::calculate_a_for_jacobian_matrix(yacobian_matrix);
                    std::complex< double > d = mashkin::calculate_a_for_jacobian_matrix(yacobian_matrix);
                    mashkin::solve_cubic_equation(eigenvalues, a, b, c, d);
                    std::cout << p4 << " " << p6 << " " << eigenvalues[0] << " " << eigenvalues[1] << " " << eigenvalues[2] << "\n";
                }
                std::cout << '\n';
            }
        }
    }
    return 0;
}