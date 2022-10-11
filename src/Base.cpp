#include "Base.h"
#include "Geometry.h"

double Base::getArea()
{
    updatePolygon();
    return abs(bg::area(polygon));
}

void Base::updatePolygon()
{
    polygon.clear(); 
    for (Line line : lines)
    {
        bg::append(polygon.outer(), line.first);
    }

    for (Arc arc : arcs)
    {
        bg::append(polygon.outer(), arc.begin);
        bg::append(polygon.outer(), arc.center);
    }
    
    // int usedLine = 0;   // Quantity of line thrown into polygon
    // int usedArc = 0;    // Quantity of arc thrown into polygon
    // for (; usedLine + usedArc < lines.size() + arcs.size(); )
    // {
    //     if (equal(lines[usedLine].first, lines[usedLine].second))
    //     {
            
    //     }
    // }
}