#include "Math.h"
#include <math.h>

/*
 * Description: Cosine Law, return cos(p3_angle)
 * Parameters: p1(Point), p2(Point), p3(Point)
 * p1 -> point
 * p2 -> point
 * p3 -> target point
 */
double cosineLaw(const Point& p1, const Point& p2, const Point& p3)
{
    double p1Len = bg::distance(p2, p3);
    double p2Len = bg::distance(p1, p3);
    double p3Len = bg::distance(p1, p2);
    long double cos = (pow(p1Len, 2) + pow(p2Len, 2) - pow(p3Len, 2)) / (2 * p1Len * p2Len);

    return cos;
}


