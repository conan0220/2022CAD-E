/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-17 00:59:36
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-25 00:52:47
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
#include "Math.h"

/// @brief Father node of Assembly, Copper, Silkscreen
class Base
{
public:
    Base() {};
    ~Base() {}
    
    
    
    double getArea();

    std::vector<std::variant<Line, Arc>> lines_arcs;    // orderly lines and arcs

private:
};

#endif /* _BASE_H_ */