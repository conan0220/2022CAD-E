#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> Point2D;      // point
typedef bg::model::segment<Point2D> Line;             // line
typedef bg::model::polygon<Point2D> Polygon;          // Points

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include "Math.h"
#include "Arc.h"


namespace boost { namespace geometry
{

// extra function set under boost::geometry
namespace extra
{
bool equal(const Point2D& p1, const Point2D& p2);

bool equal(const Line& l1, const Line& l2);

double getAngle(const double& x, const double& y, const int& mode = 0);

double getAngle(const Point2D& center, const Point2D& point, const int& mode = 0);

double degreeToRadian(const double& degree);

double radianToDegree(const double& radian);

double nomalizeAngle(const double& angle, const int& mode = 0);

void standardization(Point2D& p);

template <typename T>
void moveBoundary(T& data, const double& distance, Point2D directionVector);

Point2D getMiddle(const Point2D& first, const Point2D& second);



// template <typename T>
// void moveBoundary(T& data, const double& distance, Point2D directionVector) {}

// /**
//  * Move a boundary line by a given distance in a given direction.
//  * @param data The boundary line to move.
//  * @param distance The distance to move the line.
//  * @param directionVector The direction in which to move the line.
//  * @return None.
//  */
// template < >
// void moveBoundary(Line& data, const double& distance, Point2D directionVector)
// {
//     standardization(directionVector);
//     double dx = directionVector.x() * distance;
//     double dy = directionVector.y() * distance;

//     data.first.x(data.first.x() + dx);
//     data.first.y(data.first.y() + dy);
//     data.second.x(data.second.x() + dx);
//     data.second.y(data.second.y() + dy);
// }

// /**
//  * Displacement arc.
//  * @return None.
//  */
// template < >
// void moveBoundary<Arc>(Arc& data, const double& distance, Point2D directionVector)
// {
//     std::cout << "hi";
// }



}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost

#endif /* _GEOMETRY_H_*/