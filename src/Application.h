/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-10 18:32:35
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-02 17:20:18
 * @FilePath: \2022CAD-E\src\Application.h
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"

class Application
{
public:
    Application();
    ~Application() {}

    Assembly assembly;
    std::vector<Copper> coppers;
    std::vector<Silkscreen> silkscreens;

private:
    void preProcessInputData();
    void processSilkscreen();
    void preProcessSilkscreenData();

    void outputToTxt(std::string filePath);

};

#endif /* _APPLICATION_H_ */