#ifndef _MATH_
#define _MATH_

#include <math.h>
#include <iostream>

#include "Geometry.h"

#define PI		3.14159265358979323846

namespace math
{
    
double cosineLaw(const Point2D& p1, const Point2D& p2, const Point2D& p3);

void roundToDecimal(double& num, int decimalPlace);
}

#endif /* _MATH_ */