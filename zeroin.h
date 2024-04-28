#ifndef MATH_MODELING_ZEROIN_H
#define MATH_MODELING_ZEROIN_H
#include <functional>

double zeroin(double left, double right, std::function< double(double) > f, double tol, int *flag);
#endif
