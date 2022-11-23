/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-17 00:59:36
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-23 13:41:14
 * @FilePath: /2022CAD-E/src/Base.h
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
#include <variant>
#include "Geometry.h"
#include "Arc.h" 

/// @brief Father node of Assembly, Copper, Silkscreen
class Base
{
public:
    Base() {};
    ~Base() {}
    
    double getArea();
    void updatePolygon();
    
    std::vector<Line> lines;
    std::vector<Arc> arcs;
    std::vector<std::variant<Line, Arc>> lines_arcs;
    Polygon polygon;    // closed path of points

private:
};

#endif /* _BASE_H_ */