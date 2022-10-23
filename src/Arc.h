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

    double getArea() const;
    std::vector<double> getPositionOnArc(double theta) const;
    
    Point begin;
    Point end;
    Point center;
    bool clockWise;
    double radius;
    double beginDegree;
    double endDegree;
    double degree;  // degree between beginDegree and endDegree

private:
    double getDegreeBetweenBeginAndEnd() const;
    
};

#endif /* _ARC_H_ */