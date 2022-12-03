/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-11 22:04:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-02 16:13:24
 * @FilePath: \2022CAD-E\src\Geometry.cpp
 * @Description: This library deals exclusively with geometry.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Geometry.h"
#include "Math.h"
#include "Arc.h"

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
bool equal(const Point2D& p1, const Point2D& p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

/**
 * Check if two lines identical.
 * @param l1 First line.
 * @param l2 Second line.
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
double getAngle(const Point2D& center, const Point2D& point)
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
        angle = PI - angle;
    else if (x < 0 && y < 0)         // third quadrant
        angle += PI;
    else if (x >= 0 && y < 0)        // forth quadrant
        angle = 2 * PI - angle;

    return angle;
}

/**
 * Get the degree counterclockwise from the first quadrant. For example, center = (0, 0), point = (-1, 0), return 180.
 * @param center
 * @param point
 * @return Return degree counterclockwise from the first quadrant.
 */
double getDegree(const Point2D& center, const Point2D& point)
{
    // convert to theta
    double degree = getAngle(center, point) * 180 / PI;

    return degree;
}

// Theta to angle. If over 360, function will convert it to 360 below, then transform to angle. Ex. 540 -> 180 -> 3.14159.
double degreeToAngle(double degree)
{
    degree = std::fmod(degree, 360);

    // ex. -30 -> 330
    if (degree < 0)
        degree += 360;
    
    degree = degree * PI / 180;

    return degree;
}


/**
 * Displacement line.
 * @return None.
 */
template <>
void moveBoundary<Line>(Line& data, double distance, Point2D directionVector)
{
    standardization(directionVector);
    directionVector.x(directionVector.x() * distance);
    directionVector.y(directionVector.y() * distance);
    data.first.x(data.first.x() + directionVector.x());
    data.first.y(data.first.y() + directionVector.y());
    data.second.x(data.second.x() + directionVector.x());
    data.second.y(data.second.y() + directionVector.y());
}

/**
 * Displacement arc.
 * @return None.
 */
template <>
void moveBoundary<Arc>(Arc& data, double distance, Point2D directionVector)
{
    std::cout << "hi";
}


/**
 * Standardized parameter.
 * @param p Two dimensional Point2D.
 * @return None.
 */
void standardization(Point2D& p)
{
    double r = sqrt(p.x() * p.x() + p.y() * p.y());
    p.x(p.x() / r);
    p.y(p.y() / r);
}


}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost