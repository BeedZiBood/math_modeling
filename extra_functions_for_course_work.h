#ifndef MATH_MODELING_EXTRA_FUNCTIONS_FOR_COURSE_WORK_H
#define MATH_MODELING_EXTRA_FUNCTIONS_FOR_COURSE_WORK_H
#include <vector>
#include <complex>

namespace mashkin
{
    using comp = std::complex< double >;
    using vec = std::vector< comp >;
    void calculate_yacobian_matrix(vec& yac, const comp& x1, const comp& x2, double p1, double p2, double p3, double p4, double p5);

    std::complex< double > calculate_a_for_jacobian_matrix(const vec& yac_matrix);
    std::complex< double > calculate_b_for_jacobian_matrix(const vec& yac_matrix);
    std::complex< double > calculate_c_for_jacobian_matrix(const vec& yac_matrix);
    std::complex< double > calculate_d_for_jacobian_matrix(const vec& yac_matrix);

    double calculate_a_for_x1(double p4);
    double calculate_b_for_x1(double p1, double p2, double p3, double p4, double p5);
    double calculate_c_for_x1(double p1, double p2, double p3, double p4, double p5, double p6);
    double calculate_d_for_x1(double p1, double p3, double p4);
}
#endif
