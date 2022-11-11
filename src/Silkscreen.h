/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-17 00:59:36
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-11 15:25:46
 * @FilePath: /2022CAD-E/src/Silkscreen.h
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#ifndef _SILKSCREEN_H_
#define _SILKSCREEN_H_

#include "Base.h"

/// @brief A  component;
class Silkscreen : public Base
{
public:
    static double silkscreenLen;

    Silkscreen() {};
    ~Silkscreen() {};
};


#endif /* _SILKSCREEN_H_ */