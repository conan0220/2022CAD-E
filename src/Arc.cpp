#include "Arc.h"
#include <iostream>

Arc::Arc(Point begin, Point end, Point center, bool clockWise)
    : begin(begin), end(end), center(center), clockWise(clockWise)
{
    calculateRadius();
}

void Arc::calculateRadius()
{
    radius = sqrt(pow(begin.x() - center.y(), 2) + pow(begin.y() - center.y(), 2));
}