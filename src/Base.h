#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
#include <variant>
#include "Geometry.h"
#include "Arc.h" 
#include "Math.h"

/// @brief Father node of Assembly, Copper, Silkscreen
class Base
{
public:
    Base() {};
    ~Base() {}
    
    double getArea() const;
    Polygon getPolygon() const;

    std::vector<std::variant<Line, Arc>> lines_arcs;    // orderly lines and arcs
private:
};

#endif /* _BASE_H_ */