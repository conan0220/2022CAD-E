#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> Point;      // point
typedef bg::model::segment<Point> Line;             // line
typedef bg::model::polygon<Point, true, true> Polygon;          // Points

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

/*
 * Description: check if two Point identical
 * Parameters: p1(Point), p2(Point)
 * p1 -> first point
 * p2 -> second point
 */
bool equal(const Point& p1, const Point& p2);

/*
 * Description: check if two Line identical
 * Parameters: l1(Line), l2(Line)
 * l1 -> first line
 * l2 -> second line
 */
bool equal(const Line& l1, const Line& l2);


#endif /* _GEOMETRY_H_*/