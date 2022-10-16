/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-13 13:23:01
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-10-17 00:45:59
 * @FilePath: \2022CAD-E\src\Math.cpp
 * @Description: Bunch of mathematical logical.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Math.h"
#include <math.h>

namespace math
{

/**
 * Cosine Law, cos(p3_angle) = (p1^2 + p2^2 - p3^2) / (2 * p1 * p2).
 * @param p1 
 * @param p2
 * @param p3 Target point.
 * @return Return cos(p3_angle).
 */
double cosineLaw(const Point& p1, const Point& p2, const Point& p3)
{
    double p1Len = bg::distance(p2, p3);
    double p2Len = bg::distance(p1, p3);
    double p3Len = bg::distance(p1, p2);
    long double cos = (pow(p1Len, 2) + pow(p2Len, 2) - pow(p3Len, 2)) / (2 * p1Len * p2Len);

    return cos;
}

}
