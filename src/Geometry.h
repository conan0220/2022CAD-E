/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-11 22:04:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-01 00:57:31
 * @FilePath: /2022CAD-E/src/Geometry.h
 * @Description: This library deals exclusively with geometry.
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> Point2D;      // point
typedef bg::model::segment<Point2D> Line;             // line
typedef bg::model::polygon<Point2D> Polygon;          // Points

#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_


namespace boost { namespace geometry
{

// extra function set under boost::geometry
namespace extra
{
bool equal(const Point2D& p1, const Point2D& p2);

bool equal(const Line& l1, const Line& l2);

double getAngle(const Point2D& center, const Point2D& point);

double getDegree(const Point2D& center, const Point2D& point);

double degreeToAngle(double degree);

template <typename T1>
void moveBoundary(T1& data, double distance, Point2D directionVector);

void standardization(Point2D& p);


}   // namespace boost::geometry::extra

}   // namespace boost::geometry

}   // namespace boost

#endif /* _GEOMETRY_H_*/