#include "Arc.h"
#include "Math.h"
#include <iostream>


Arc::Arc(Point2D begin, Point2D end, Point2D center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise) {
    radius = bg::distance(begin, center);
    beginAngle = bg::extra::getAngle(center, begin, 0);
    endAngle = bg::extra::getAngle(center, end, 0);
    angle = getAngleBetweenBeginAndEnd();
}

void Arc::rewrite(Point2D begin, Point2D end, Point2D center, bool clockWise) {
    radius = bg::distance(begin, center);
    beginAngle = bg::extra::getAngle(center, begin, 0);
    endAngle = bg::extra::getAngle(center, end, 0);
    angle = getAngleBetweenBeginAndEnd();
}


double Arc::getArea() const {
    return PI * pow(radius, 2) * (angle / (2 * PI));
}

/**
 * Get the coordinate of the point on the arc.
 * @param angle The angle of the point from the starting point of the arc, measured in radians and the clockwise of object.
 * @param mode  The mode of the input angle, 0 for radian (default), 1 for degree.
 * @return Return a Point2D which contains the coordinate of position on arc. First element is x, second is y.
 */
Point2D Arc::getPositionOnArc(double angle_t, int mode) const {
    angle_t = bg::extra::nomalizeAngle(angle_t, mode);
    // convert degree to radian
    if (mode == 1)
        angle_t = bg::extra::degreeToRadian(angle_t);
    if (clockWise == true)
        angle_t = -angle_t;
    Point2D position;
    position.x(center.x() + radius * cos(angle_t + beginAngle));
    position.y(center.y() + radius * sin(angle_t + beginAngle));
    return position;
}

/**
 * Get degree between beginDegree and endDegree, so you have to set beginDegree and endDegree first.
 * @return Degree.
 */
double Arc::getAngleBetweenBeginAndEnd(int mode) const {
    // if the start and end point are identical then denote that arc is a circle
    if (bg::extra::equal(begin, end))
        return 2 * PI;
    // target angle
    double angle_t = 0;
    if (endAngle > beginAngle) {
        clockWise == true ? angle_t = 2 * PI - (endAngle - beginAngle) : angle_t = endAngle - beginAngle;
    } else if (beginAngle > endAngle) {
        clockWise == true ? angle_t = beginAngle - endAngle : angle_t = 2 * PI - (beginAngle - endAngle);
    }
    if (mode == 0) {
        return angle_t;
    } else { 
        return bg::extra::radianToDegree(angle_t);
    }
}