#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
#include "Geometry.h"
#include "Arc.h" 

/// @brief Father node of Assembly, Copper, Silkscreen
class Base
{
public:
    Base() {};
    ~Base() {}
    
    double getArea();
    
    std::vector<Line> lines;
    std::vector<Arc> arcs;
    Polygon polygon;    // closed path of points

private:
    void updatePolygon();
};

#endif /* _BASE_H_ */