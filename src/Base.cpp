/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-17 01:01:38
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-23 14:19:48
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
 * Get polygon area, you must use updatePolygon() to push data into polygon first
 * @return {double}
 */
double Base::getArea()
{
    double area = abs(bg::area(polygon));
    for (Arc arc : arcs)
    {
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
    return area;
}



/**
 * Add lines and arcs to polygon.
 * @return None.
 */
void Base::updatePolygon()
{
    for (auto element : lines_arcs)
    {
        // Element type is Line?
        if (std::holds_alternative<Line>(element))
        {
            bg::append(polygon.outer(), std::get<Line>(element).first);
        }
        else if (std::holds_alternative<Arc>(element))
        {
            bg::append(polygon.outer(), std::get<Arc>(element).begin);
            bg::append(polygon.outer(), std::get<Arc>(element).center);
        }
    }
    



    // if (type == "line")
    // {
    //     bg::append(polygon.outer(), lines.back().first);
    // }
    // else if (type == "arc")
    // {
    //     bg::append(polygon.outer(), arcs.back().begin);
    //     bg::append(polygon.outer(), arcs.back().center);
    // }
}

