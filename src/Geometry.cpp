#include "Geometry.h"

bool equal(const Point& p1, const Point& p2)
{
    return p1.x() == p2.x() && p1.y() == p2.y();
}

bool equal(const Line& l1, const Line& l2)
{
    return (equal(l1.first, l2.first) && equal(l1.second, l2.second)) || (equal(l1.first, l2.second) && equal(l1.second, l2.first));
}