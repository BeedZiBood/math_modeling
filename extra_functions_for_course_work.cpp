#include "extra_functions_for_course_work.h"

namespace mashkin
{
    double calculate_a_for_x1(double p4)
    {
        return -1 - p4;
    }

    double calculate_b_for_x1(double p1, double p2, double p3, double p4, double p5) {
        return p1 - (p2 * p4) + (p4 * p1) - (p4 * p4 * p2) + p4 + 1 - p5 - (p4 * p3) - (p3 * p4 * p4);
    }

    double calculate_c_for_x1(double p1, double p2, double p3, double p4, double p5, double p6) {
        return p1 - (p1 * p2 * p4) - (p4 * p4 * p1 * p2) + (p4 * p1) + (p1 * p5) - (p3 * p4 * p6) - (p3 * p2 * p4 * p4) + (p4 * p3) - (p3 * p4 * p4 * p6) - (p3 * p4 * p4 * p4 * p2) + (p3 * p4 * p4);
    }

    double calculate_d_for_x1(double p1, double p3, double p4) {
        return p3 * p4 * p1 * (1 + p4);
    }

    std::complex< double > calculate_a_for_jacobian_matrix(const vec& yac_matrix) {
        return -1.0;
    }

    std::complex< double > calculate_b_for_jacobian_matrix(const vec& yac_matrix) {
        return yac_matrix[0] + yac_matrix[4] + yac_matrix[8];
    }

    std::complex<double> calculate_c_for_jacobian_matrix(const vec& yac) {
        return (yac[2] * yac[6]) - (yac[0] * yac[4]) - (yac[0] * yac[8]) - (yac[4] * yac[8]) + (yac[5] * yac[7]) + (yac[1] * yac[3]);
    }

    std::complex<double> calculate_d_for_jacobian_matrix(const vec& yac) {
        std::complex< double > first_comp = yac[0] * yac[4] * yac[8];
        std::complex< double > second_comp = yac[1] * yac[5] * yac[6];
        std::complex< double > third_comp = yac[2] * yac[3] * yac[7];
        std::complex< double > fourth_comp = yac[2] * yac[4] * yac[6];
        std::complex< double > fifth_comp = yac[0] * yac[5] * yac[7];
        std::complex< double > sixth_comp = yac[1] * yac[3] * yac[8];
        return first_comp + second_comp + third_comp - fourth_comp - fifth_comp - sixth_comp;
    }

    void calculate_yacobian_matrix(vec& yac, const comp& x1, const comp& x2, double p1, double p2, double p3, double p4, double p5)
    {
        yac[0] = ((-x2 + 1.0 - 2.0 * x2) / p2 - p4);
        yac[1] = ((p1 - x1) / p2);
        yac[2] = (0.0);
        yac[3] = (-x2 / p3);
        yac[4] = ((-p1 - x1) / p3 - p4);
        yac[5] = (p5 / p3);
        yac[6] = (0.0);
        yac[7] = (0.0);
        yac[8] = (-1.0 - p4);
    }
}