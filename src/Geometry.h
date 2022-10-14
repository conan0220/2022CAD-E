#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> Point;      // point
typedef bg::model::segment<Point> Line;             // line
typedef bg::model::polygon<Point> Polygon;          // Points

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

namespace boost { namespace geometry
{

namespace extra
{

bool equal(const Point& p1, const Point& p2);

bool equal(const Line& l1, const Line& l2);

double getAngle(const Point& center, const Point& point);

double getDegree(const Point& center, const Point& point);

}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost

#endif /* _GEOMETRY_H_*/