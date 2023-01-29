#include "Base.h"
#include "Math.h"
#include "Application.h"
#include <cmath>

/**
 * Get polygon area.
 * @return {double}
 */
double Base::getArea() const {
    Polygon polygon = getPolygon();
    double area = 0;
    for (const std::variant<Line, Arc>& element : lines_arcs) {
        if (std::holds_alternative<Arc>(element)) {
            Arc arc = std::get<Arc>(element);
            Point2D posi = bg::extra::getMiddle(arc.getPositionOnArc(arc.angle / 2), arc.center);
            if (bg::within(posi, polygon)) {  // detect arc is outer or inner
                area -= arc.getArea();  // inner, minus arc area
            } else {
                area += arc.getArea();  // outer, add arc area
            }
        }
    }
    area += abs(bg::area(polygon));
    return area;
}

 // closed path of points
Polygon Base::getPolygon() const {
    Polygon polygon;
    if (lines_arcs.empty())
        return polygon;
    std::vector<Point2D> points;
    for (const std::variant<Line, Arc>& element : lines_arcs) {
        if (std::holds_alternative<Line>(element)) {            // Element type is Line
            bg::append(polygon.outer(), std::get<Line>(element).first);
            points.push_back(std::get<Line>(element).first);
        } else if (std::holds_alternative<Arc>(element)) {      // Element type is Arc
            Arc arc = std::get<Arc>(element);
            bg::append(polygon.outer(), arc.begin);
            bg::append(polygon.outer(), arc.center);
            points.push_back(arc.begin);
            points.push_back(arc.center);
        }
    }
    if (std::holds_alternative<Line>(lines_arcs[0])) {           
        bg::append(polygon.outer(), std::get<Line>(lines_arcs[0]).first);
        points.push_back(std::get<Line>(lines_arcs[0]).first);
    } else if (std::holds_alternative<Arc>(lines_arcs[0])) {      
        Arc arc = std::get<Arc>(lines_arcs[0]);
        bg::append(polygon.outer(), arc.begin);
        bg::append(polygon.outer(), arc.center);
        points.push_back(arc.begin);
        points.push_back(arc.center);
    }
    // Application::outputPoint2DToTxt("../res/output.txt", points);
    return polygon;
}