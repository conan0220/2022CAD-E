/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-13 13:21:49
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-10-18 13:41:29
 * @FilePath: \2022CAD-E\src\Math.h
 * @Description: Bunch of mathematical logical.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#ifndef _MATH_
#define _MATH_

#include <math.h>

#include "Geometry.h"

#define PI		3.14159265358979323846

namespace math
{

double cosineLaw(const Point& p1, const Point& p2, const Point& p3);

}

#endif /* _MATH_ */