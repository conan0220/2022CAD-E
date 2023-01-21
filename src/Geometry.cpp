#include "Geometry.h"


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
 * Helper function to calculate the angle counterclockwise from the first quadrant.
 * @param x  X coordinate of the point.
 * @param y  Y coordinate of the point.
 * @param mode  Mode of the output angle, 0 for radian (default), 1 for degree.
 * @return Return angle counterclockwise from the first quadrant.
 */
double getAngle(const double& x, const double& y, const int& mode)
{
    double z = sqrt(x * x + y * y);
    double angle = asin(math::abs(y) / z);

    if (x >= 0 && y >= 0)             // first quadrant
        angle = angle;
    else if (x < 0 && y >= 0)         // second quadrant
        angle = PI - angle;
    else if (x < 0 && y < 0)         // third quadrant
        angle += PI;
    else if (x >= 0 && y < 0)        // forth quadrant
        angle = 2 * PI - angle;

    if (mode == 0)
        return angle;
    else
        return angle * 180 / PI;
}

/**
 * Get the angle or degree counterclockwise from the first quadrant. For example, center = (0, 0), point = (-1, 0), return 3.14159... or 180.
 * @param center A point representing the center of a circle.
 * @param point A point on the circumference of the circle.
 * @param mode  Mode of the output angle, 0 for radian (default), 1 for degree.
 * @return Return angle or degree counterclockwise from the first quadrant.
 */
double getAngle(const Point2D& center, const Point2D& point, const int& mode)
{
    // it doesn't have angle
    if (equal(center, point))
        return -1;

    // calculate the edges of triangle
    double x = point.x() - center.x();
    double y = point.y() - center.y();

    // return angle in radian or degree
    return getAngle(x, y, mode);
}

/**
 * Convert a degree value to a radian value.
 * @param degree The degree value to convert.
 * @return The radian value.
 */
double degreeToRadian(const double& degree)
{
    return degree * PI / 180;
}

/**
 * Convert a radian value to a degree value.
 * @param radian The radian value to convert.
 * @return The radian value.
 */
double radianToDegree(const double& radian)
{
    return radian * 180 / PI;
}

/**
 * Normalizes an angle to a value between 0 and 2*PI in radians or 0 and 360 in degrees, depending on the mode.
 * @param angle The angle to normalize.
 * @param mode Specifies whether the angle is in radians (mode=0) (default) or degrees (mode=1).
 * @return The normalized angle.
 */
double nomalizeAngle(const double& angle, const int& mode)
{
    if (mode == 0)
    {
        double radian = std::fmod(angle, 2 * PI);
        if (radian == 0 && angle >= 2 * PI)
            return 2 * PI;
        if (radian < 0)
            radian += 2 * PI;
        return radian;
    }
    else if (mode == 1)
    {
        double degree = std::fmod(angle, 360);
        if (degree == 0 && angle >= 360)
            return 360;
        if (degree < 0)
            degree += 360;
        return degree;
    }
    return angle;
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

void moveBoundary(Line& data, const double& distance, Point2D directionVector)
{
    standardization(directionVector);
    double dx = directionVector.x() * distance;
    double dy = directionVector.y() * distance;

    data.first.x(data.first.x() + dx);
    data.first.y(data.first.y() + dy);
    data.second.x(data.second.x() + dx);
    data.second.y(data.second.y() + dy); 
}


}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost