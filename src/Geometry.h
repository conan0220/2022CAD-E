#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>

namespace bg = boost::geometry;
typedef bg::model::d2::point_xy<double> Point;      // point
typedef bg::model::segment<Point> Line;             // line
typedef bg::model::polygon<Point, true, true> Polygon;          // Points