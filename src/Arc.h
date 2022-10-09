#ifndef _ARC_H_
#define _ARC_H_

#include "Geometry.h"

/// @brief Arc
class Arc
{
public:
    Arc() {};
    Arc(Point begin, Point end, Point center, bool clockWise);
    ~Arc() {};

    Point begin;
    Point end;
    Point center;
    bool clockWise;
    double radius;

private:
    void calculateRadius();
};

#endif /* _ARC_H_ */