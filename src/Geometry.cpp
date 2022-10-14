#include "Geometry.h"
#include "Math.h"

namespace boost { namespace geometry
{

namespace extra 
{
/*
 * Description: check if two Point identical
 * Parameters: p1(Point), p2(Point)
 * p1 -> first point
 * p2 -> second point
 */
bool equal(const Point& p1, const Point& p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

/*
 * Description: check if two Line identical
 * Parameters: l1(Line), l2(Line)
 * l1 -> first line
 * l2 -> second line
 */
bool equal(const Line& l1, const Line& l2)
{
    return (equal(l1.first, l2.first) && equal(l1.second, l2.second)) || (equal(l1.first, l2.second) && equal(l1.second, l2.first));
}


/*
 * Description: get the angle of point 
 * Parameters: center(Point), point(Point)
 * center -> center point
 * point -> target point
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

/*
 * Description: get the degree of point 
 * Parameters: center(Point), point(Point)
 * center -> center point
 * point -> target point
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

    double degree = angle * 180 / M_PI;

    return degree;
}

}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost