/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-11 22:04:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-10-17 00:49:26
 * @FilePath: \2022CAD-E\src\Geometry.cpp
 * @Description: This library deals exclusively with geometry.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Geometry.h"
#include "Math.h"

namespace boost { namespace geometry
{

// extra function set under boost::geometry
namespace extra 
{

/**
 * Check if two points identical.
 * @param p1 First point.
 * @param p2 Second point.
 * @return If p1 identical to p2 return true, otherwise false.
 */
bool equal(const Point& p1, const Point& p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

/**
 * Check if two lines identical.
 * @param p1 First line.
 * @param p2 Second line.
 * @return If l1 identical to l2 return true, otherwise false.
 */
bool equal(const Line& l1, const Line& l2)
{
    return (equal(l1.first, l2.first) && equal(l1.second, l2.second)) || (equal(l1.first, l2.second) && equal(l1.second, l2.first));
}

/**
 * Get the angle counterclockwise from the first quadrant. For example, center = (0, 0), point = (-1, 0), return 3.14159...
 * @param center 
 * @param point
 * @return Return angle counterclockwise from the first quadrant.
 */
double getAngle(const Point& center, const Point& point)
{
    // it doesn't have angle
    if (equal(center, point))
        return -1;

    // calculate the edges of triangle
    double x = point.x() - center.x();
    double y = point.y() - center.y();
    double z = sqrt(x * x + y * y);

    // angle we calculate
    double angle = asin(math::abs(y) / z);

    if (x >= 0 && y >= 0)             // first quadrant
        angle = angle;
    else if (x < 0 && y >= 0)         // second quadrant
        angle = M_PI - angle;
    else if (x < 0 && y < 0)         // third quadrant
        angle += M_PI;
    else if (x >= 0 && y < 0)        // forth quadrant
        angle = 2 * M_PI - angle;

    return angle;
}

/**
 * Get the degree counterclockwise from the first quadrant. For example, center = (0, 0), point = (-1, 0), return 180.
 * @param center
 * @param point
 * @return Return degree counterclockwise from the first quadrant.
 */
double getDegree(const Point& center, const Point& point)
{
    // it doesn't have angle
    if (equal(center, point))
        return -1;

    // calculate the edges of triangle
    double x = point.x() - center.x();
    double y = point.y() - center.y();
    double z = sqrt(x * x + y * y);

    // angle we calculate
    double angle = asin(math::abs(y) / z);

    if (x >= 0 && y >= 0)             // first quadrant
        angle = angle;
    else if (x < 0 && y >= 0)         // second quadrant
        angle = M_PI - angle;
    else if (x < 0 && y < 0)         // third quadrant
        angle += M_PI;
    else if (x >= 0 && y < 0)        // forth quadrant
        angle = 2 * M_PI - angle;

    // convert to theta
    double degree = angle * 180 / M_PI;

    return degree;
}

}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost