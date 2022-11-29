/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 20:06:05
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-11-29 02:16:10
 * @FilePath: /2022CAD-E/src/Application.cpp
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
    std::cout << assembly.getArea() << std::endl;
    bg::extra::moveBoundary<Line>(std::get<Line>(assembly.lines_arcs[0]), 2, Point2D(3, 4));
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
            Line dataTemp = Line(Point2D(data[0], data[1]), Point2D(data[2], data[3]));
            if (targetComponent == "assembly")
            {
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            }
            else if (targetComponent == "copper")
            {
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            }
        }
        else if (text::isTargetInString(str, "arc"))
        {
            bool clockWiseTemp = !text::isTargetInString(str, "CCW");
            Arc dataTemp = Arc(Point2D(data[0], data[1]), Point2D(data[2], data[3]), Point2D(data[4], data[5]), clockWiseTemp);
            if (targetComponent == "assembly")
            {
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            }
            else if (targetComponent == "copper")
            {
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
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
 * Put Assembly data into Silkscreens separately
 * @return None
 */
void Application::preProcessSilkscreenData()
{
    
}