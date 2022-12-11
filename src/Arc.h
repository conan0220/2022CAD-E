/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 02:15:28
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-11 12:15:29
 * @FilePath: /2022CAD-E/src/Arc.h
 * @Description: Angle -> radian (default). 
 * 
 * Example:
 *  radian -> 3.14
 *  degree -> 180
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#ifndef _ARC_H_
#define _ARC_H_

#include "Geometry.h"

/// @brief Arc
class Arc
{
public:
    Arc() {};
    Arc(Point2D begin, Point2D end, Point2D center, bool clockWise);
    ~Arc() {};

    double getArea() const;
    std::vector<double> getPositionOnArc(double angle_t, int mode = 0) const;
    
    Point2D begin;
    Point2D end;
    Point2D center;
    bool clockWise;
    double radius;
    double beginAngle;
    double endAngle;
    double angle;  // degree between beginDegree and endDegree

private:
    double getAngleBetweenBeginAndEnd() const;
    
};

#endif /* _ARC_H_ */