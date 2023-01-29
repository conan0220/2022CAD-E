/*
* For example:
*   radian -> 3.14
*   degree -> 180
*/
#ifndef _ARC_H_
#define _ARC_H_

#include "Geometry.h"

/// @brief angle: radian(default)
class Arc {
public:
    Arc() {};
    Arc(Point2D begin, Point2D end, Point2D center, bool clockWise);
    ~Arc() {};

    double getArea() const;
    Point2D getPositionOnArc(double angle_t, int mode = 0) const;
    void rewrite(Point2D begin, Point2D end, Point2D center, bool clockWise);

    friend std::ostream& operator<<(std::ostream& os, const Arc& arc);
    
    Point2D begin;
    Point2D end;
    Point2D center;
    bool clockWise;
    double radius;
    double beginAngle;
    double endAngle;
    double angle;  // degree between beginDegree and endDegree

private:
    double getAngleBetweenBeginAndEnd(int mode = 0) const;
};

#endif /* _ARC_H_ */