#include "Base.h"
#include "Geometry.h"

#include "Math.h"
#include <cmath>


/**
 * Get polygon area, you must use updatePolygon() to push data into polygon first
 * @return {double}
 */
double Base::getArea()
{
    double area = abs(bg::area(polygon));
    for (Arc arc : arcs)
    {
        std::vector<double> posi = arc.getPosition_On_Arc(arc.degree / 2);

        // detect arc is outer or inner
        if (bg::within(Point(posi[0], posi[1]), polygon))
        {
            // inner, minus arc area
            area -= arc.getArea();
        }
        else
        {
            // outer, add arc area
            area += arc.getArea();
        }
    }
    return area;
}



/**
 * Add latest line or arc back to polygon.
 * @param type "line" or "arc".
 * @return None.
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

