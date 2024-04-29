#ifndef MATH_MODELING_COMPARISON_BETWEEN_DOUBLES_H
#define MATH_MODELING_COMPARISON_BETWEEN_DOUBLES_H
#include <limits>
#include <cmath>

namespace mashkin
{
    template<typename TReal>
    static bool isApproximatelyEqual(TReal a, TReal b, TReal tolerance = std::numeric_limits<TReal>::epsilon())
    {
        TReal diff = std::fabs(a - b);
        if (diff <= tolerance)
            return true;

        if (diff < std::fmax(std::fabs(a), std::fabs(b)) * tolerance)
            return true;

        return false;
    }

    template< class TReal >
    static bool isDefinitelyGreaterThan(TReal a, TReal b, TReal tolerance = std::numeric_limits<TReal>::epsilon())
    {
        TReal diff = a - b;
        if (diff > tolerance)
            return true;

        if (diff > std::fmax(std::fabs(a), std::fabs(b)) * tolerance)
            return true;

        return false;
    }

    template< class TReal >
    static bool isDefinitelyLessThan(TReal a, TReal b, TReal tolerance = std::numeric_limits<TReal>::epsilon())
    {
        TReal diff = a - b;
        if (diff < tolerance)
            return true;

        if (diff < std::fmax(std::fabs(a), std::fabs(b)) * tolerance)
            return true;

        return false;
    }
}
#endif
