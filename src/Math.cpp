#include "Math.h"

namespace math
{
/**
 * Cosine Law, cos(p3_angle) = (p1^2 + p2^2 - p3^2) / (2 * p1 * p2).
 * @param p1 
 * @param p2
 * @param p3 Target point.
 * @return Return cos(p3_angle).
 */
double cosineLaw(const Point2D& p1, const Point2D& p2, const Point2D& p3) {
    double p1Len = bg::distance(p2, p3);
    double p2Len = bg::distance(p1, p3);
    double p3Len = bg::distance(p1, p2);
    long double cos = (pow(p1Len, 2) + pow(p2Len, 2) - pow(p3Len, 2)) / (2 * p1Len * p2Len);
    return cos;
}

/**
 * roundToDecimal function, round the number to the specified decimal place.
 * @param num The number that need to be rounded.
 * @param decimalPlace The number of decimal places to round to.
 */
void roundToDecimal(double& num, int decimalPlace) {
    double factor = pow(10, decimalPlace);
    num = round(num * factor) / factor;
}

}   // namespace math
