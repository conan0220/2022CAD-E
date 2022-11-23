/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 02:15:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-22 14:07:54
 * @FilePath: /2022CAD-E/src/Arc.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Arc.h"
#include "Math.h"
#include <iostream>


Arc::Arc(Point begin, Point end, Point center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise)
{
    radius = bg::distance(begin, center);
    beginDegree = bg::extra::getDegree(center, begin);
    endDegree = bg::extra::getDegree(center, end);
    degree = getDegreeBetweenBeginAndEnd();
}

double Arc::getArea() const 
{
    return PI * pow(radius, 2) * (degree / 360);
}

/**
 * Get the coordinate depend on theta. Theta starts from beginDegree. For example, if theta = 10, then actually theta we find is beginDegree + theta. 
 * @param theta Theta must be positive, or function will implicitly convert it to positive. Theta should be lower than the member variable "degree". If theta out of range then function will impicitly convert it to member variable "degree". For example, theta = 10, degree = 8, function will convert theta to 8. Theta = -9, degree = 7, function will convert theta to 9 then to 7.
 * @return Return a vector which contains the coordinate of position on arc. First element is x, second is y.
 */
std::vector<double> Arc::getPositionOnArc(double theta) const
{
    theta = abs(theta);

    if (theta > degree)
        theta = degree;

    std::vector<double> position;
    
    clockWise == true ? theta = beginDegree - theta : theta = beginDegree + theta;

    position.push_back(center.x() + radius * cos(bg::extra::degreeToAngle(theta)));
    position.push_back(center.y() + radius * sin(bg::extra::degreeToAngle(theta)));

    return position;
}

/**
 * Get degree between beginDegree and endDegree, so you have to set beginDegree and endDegree first.
 * @return Degree.
 */
double Arc::getDegreeBetweenBeginAndEnd() const
{
    // if the start and end point are identical then denote that arc is a circle
    if (bg::extra::equal(begin, end))
        return 360;

    // target degree
    double degree = 0;

    if (endDegree > beginDegree)
        clockWise == true ? degree = 360 - (endDegree - beginDegree) : degree = endDegree - beginDegree;
    else if (beginDegree > endDegree)
        clockWise == true ? degree = beginDegree - endDegree : degree = 360 - (beginDegree - endDegree);

    return degree;
}