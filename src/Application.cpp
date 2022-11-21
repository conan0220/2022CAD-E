/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 20:06:05
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-20 19:38:54
 * @FilePath: \2022CAD-E\src\Application.cpp
 * @Description: 
 * 
 * Copyright (c) 2022 by conan0220 conanhuang8382@gmail.com, All Rights Reserved. 
 */
#include "Application.h"
#include "Text.h"
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"
#include "Math.h"

Application::Application()
{
    // read data and set in specific component
    preProcessInputData();
    processSilkscreen();
}

/**
 * Read data and set it in specific component. For example, Assembly, Copper.
 * @return None.
 */
void Application::preProcessInputData()
{
    std::vector<std::string> text = text::loadFile("../res/testing-data.txt");
    std::string targetComponent = "";  // current component we focus
    for (std::string str : text)    // line by line
    {
        std::vector<double> data = text::getDataFromString(str);      //  numbers in the string

        // identify the keyword of str
        if (text::isTargetInString(str, "line"))
        {
            Line dataTemp = Line(Point(data[0], data[1]), Point(data[2], data[3]));
            if (targetComponent == "assembly")
            {
                assembly.lines.push_back(dataTemp);
                assembly.updatePolygon("line");
            }
            else if (targetComponent == "copper")
            {
                coppers.back().lines.push_back(dataTemp);
                coppers.back().updatePolygon("line");
            }
        }
        else if (text::isTargetInString(str, "arc"))
        {
            bool clockWiseTemp = !text::isTargetInString(str, "CCW");
            Arc dataTemp = Arc(Point(data[0], data[1]), Point(data[2], data[3]), Point(data[4], data[5]), clockWiseTemp);
            if (targetComponent == "assembly")
            {
                assembly.arcs.push_back(dataTemp);
                assembly.updatePolygon("arc");
            }
            else if (targetComponent == "copper")
            {
                coppers.back().arcs.push_back(dataTemp);
                coppers.back().updatePolygon("arc");
            }
        }
        else if (text::isTargetInString(str, "coppergap"))
        {
            Copper::copperGap = data[0];
        }
        else if (text::isTargetInString(str, "copper"))
        {
            targetComponent = "copper";
            coppers.push_back(Copper());
        }
        else if (text::isTargetInString(str, "assemblygap"))
        {
            Assembly::assemblyGap = data[0];
        }
        else if (text::isTargetInString(str, "assembly"))
        {
            targetComponent = "assembly";
        }
        else if (text::isTargetInString(str, "silkscreenlen"))
        {
            Silkscreen::silkscreenLen = data[0];
        }
    }
}

void Application::processSilkscreen()
{
    preProcessSilkscreenData();
}

/**
 * Put Assembly data into Silkscreens
 * @return 
 */
void Application::preProcessSilkscreenData()
{


}