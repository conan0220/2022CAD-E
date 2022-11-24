/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-17 01:01:38
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-25 01:00:49
 * @FilePath: /2022CAD-E/src/Base.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Base.h"
#include "Geometry.h"

#include "Math.h"
#include <cmath>


/**
 * Get polygon area.
 * @return {double}
 */
double Base::getArea()
{
    Polygon polygon;    // closed path of points
    double area = 0;

    for (auto element : lines_arcs)
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

            // posi[0] -> x, posi[1] -> y
            std::vector<double> posi = arc.getPositionOnArc(arc.degree / 2);

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
    }
    area += abs(bg::area(polygon));

    return area;
}