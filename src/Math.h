#ifndef _MATH_
#define _MATH_

#include "Geometry.h"

/*
 * Description: Cosine Law, return cos(p3_angle)
 * Parameters: p1(Point), p2(Point), p3(Point)
 * p1 -> point
 * p2 -> point
 * p3 -> target point
 */
double cosineLaw(const Point& p1, const Point& p2, const Point& p3);

#endif /* _MATH_ */