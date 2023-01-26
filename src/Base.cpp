#include "Base.h"
#include "Math.h"
#include <cmath>


/**
 * Get polygon area.
 * @return {double}
 */
double Base::getArea() const
{
    Polygon polygon = getPolygon();
    double area = 0;
    for (const std::variant<Line, Arc>& element : lines_arcs)
    {
        if (std::holds_alternative<Arc>(element))
        {
            Arc arc = std::get<Arc>(element);

            Point2D posi = bg::extra::getMiddle(arc.getPositionOnArc(arc.angle / 2), arc.center);

            // detect arc is outer or inner
            if (bg::within(posi, polygon))
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
    }
    area += abs(bg::area(polygon));

    return area;
}

 // closed path of points
Polygon Base::getPolygon() const
{
    Polygon polygon;
    for (const std::variant<Line, Arc>& element : lines_arcs)
    {
        // Element type is Line?
        if (std::holds_alternative<Line>(element))
        {
            bg::append(polygon.outer(), std::get<Line>(element).first);
        }
        // Element type is Arc?
        else if (std::holds_alternative<Arc>(element))
        {
            Arc arc = std::get<Arc>(element);

            bg::append(polygon.outer(), arc.begin);
            bg::append(polygon.outer(), arc.center);
        }
    }
    return polygon;
}