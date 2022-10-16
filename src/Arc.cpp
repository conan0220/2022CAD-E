#include "Arc.h"
#include "Math.h"
#include <iostream>

Arc::Arc(Point begin, Point end, Point center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise)
{
    radius = bg::distance(begin, center);
    beginDegree = bg::extra::getDegree(center, begin);
    endDegree = bg::extra::getDegree(center, end);
}

double Arc::getTheta() const
{
    // if the start and end point are identical then denote that arc is a circle
    if (bg::extra::equal(begin, end))
        return 360;

    double theta = acos(math::cosineLaw(begin, end, center)) * 180 / M_PI;

    // identify the direction of arc then modify theta
    //
    //      code...
    //

    return theta;


}