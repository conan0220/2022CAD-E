#include "Base.h"
#include "Geometry.h"

#include "Math.h"
#include <cmath>

/*
 * Description: get polygon area, you must use updatePolygon() to push data into polygon first
 * Parameters: None
 */
double Base::getArea()
{
    double area = abs(bg::area(polygon));
    for (Arc arc : arcs)
    {
        
    }
    return area;
}

/*
 * Description: add latest line or arc to polygon
 * Parameters: type(string)
 * type -> "line" or "arc"
 */
void Base::updatePolygon(std::string type)
{
    if (type == "line")
    {
        bg::append(polygon.outer(), lines.back().first);
    }
    else if (type == "arc")
    {
        bg::append(polygon.outer(), arcs.back().begin);
        bg::append(polygon.outer(), arcs.back().center);
    }
}

