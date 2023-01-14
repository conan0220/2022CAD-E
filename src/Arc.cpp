/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 02:15:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2023-01-14 09:49:59
 * @FilePath: /2022CAD-E/src/Arc.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Arc.h"
#include "Math.h"
#include <iostream>


Arc::Arc(Point2D begin, Point2D end, Point2D center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise)
{
    radius = bg::distance(begin, center);
    beginAngle = bg::extra::getAngle(center, begin, 1);
    endAngle = bg::extra::getAngle(center, end, 1);
    angle = getAngleBetweenBeginAndEnd();
}

double Arc::getArea() const
{
    return PI * pow(radius, 2) * (angle / 2 * PI);
}

/**
 * Get the coordinate of the point on the arc.
 * @param angle The angle of the point from the starting point of the arc, measured in radians and the clockwise of object. If the angle is outside of the range [0, degree], it will be converted to the range [0, degree].
 * @param mode  The mode of the input angle, 0 for radian (default), 1 for degree.
 * @return Return a vector which contains the coordinate of position on arc. First element is x, second is y.
 */
std::vector<double> Arc::getPositionOnArc(double angle_t, int mode) const
{
    angle_t = bg::extra::nomalizeAngle(angle_t, mode);

    // convert degree to radian
    if (mode == 1)
        angle_t = bg::extra::degreeToRadian(angle_t);

    // adjust angle by the direction of the coordinate axis
    if (clockWise)
        angle_t = beginAngle - angle_t;
    else
        angle_t = beginAngle + angle_t;

    // calculate the coordinates
    std::vector<double> position;
    position.push_back(center.x() + radius * cos(angle_t));
    position.push_back(center.y() + radius * sin(angle_t));

    return position;
}

/**
 * Get degree between beginDegree and endDegree, so you have to set beginDegree and endDegree first.
 * @return Degree.
 */
double Arc::getAngleBetweenBeginAndEnd() const
{
    // if the start and end point are identical then denote that arc is a circle
    if (bg::extra::equal(begin, end))
        return 2 * PI;

    // target angle
    double angle_t = 0;

    if (endAngle > beginAngle)
        clockWise == true ? angle_t = 2 * PI - (endAngle - beginAngle) : angle_t = endAngle - beginAngle;
    else if (beginAngle > endAngle)
        clockWise == true ? angle_t = beginAngle - endAngle : angle_t = 2 * PI - (beginAngle - endAngle);

    return angle_t;
}