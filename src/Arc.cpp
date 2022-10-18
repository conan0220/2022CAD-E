#include "Arc.h"
#include "Math.h"
#include <iostream>


Arc::Arc(Point begin, Point end, Point center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise)
{
    radius = bg::distance(begin, center);
    beginDegree = bg::extra::getDegree(center, begin);
    endDegree = bg::extra::getDegree(center, end);
    degree = getDegree_Between_Begin_And_End();
}

double Arc::getArea() const 
{
    return PI * pow(radius, 2) * (degree / 360);
}

/**
 * Get degree between beginDegree and endDegree, so you have to set beginDegree and endDegree first.
 * @return Degree.
 */
double Arc::getDegree_Between_Begin_And_End() const
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