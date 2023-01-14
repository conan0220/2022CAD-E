/*
 * @Author: conan0220 conanhuang8382@gmail.com
 * @Date: 2022-10-21 20:06:05
 * @LastEditors: conan0220 conanhuang8382@gmail.com
 * @LastEditTime: 2022-12-11 00:38:06
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
    Line l1 = Line(Point2D(0, 1), Point2D(1, 0));
    bg::extra::moveBoundary<Line>(l1, 5, Point2D(5, 5));
    std::cout << l1.first.x() << " " << l1.first.y() << std::endl;
    std::cout << l1.second.x() << " " << l1.second.y() << std::endl;
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
        std::vector<double> data = text::extractNumeric(str);      //  numbers in the string

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

/**
 * Output silkscreens to txt file.
 * @param filePath File path.
 * @return None.
 */
void Application::outputToTxt(std::string filePath)
{
    std::vector<std::string> text;
    for (const Silkscreen& silkscreen : silkscreens)
    {
        text.push_back("silkscreen");
        
        for (const std::variant<Line, Arc>& element : silkscreen.lines_arcs)
        {
            // Element type is Line?
            if (std::holds_alternative<Line>(element))
            {
                Line line = std::get<Line>(element);
                text.push_back("line," + std::to_string(line.first.x()) + "," + std::to_string(line.first.y()) + "," + std::to_string(line.second.x()) + "," + std::to_string(line.second.y()));
            }
            // Element type is Arc?
            else if (std::holds_alternative<Arc>(element))
            {
                Arc arc = std::get<Arc>(element);
                text.push_back("Arc," + std::to_string(arc.begin.x()) + "," + std::to_string(arc.begin.y()) + "," + std::to_string(arc.end.x()) + "," + std::to_string(arc.end.y()) + "," + std::to_string(arc.center.x()) + "," + std::to_string(arc.center.y()) + "," + (arc.clockWise ? "CW" : "CCW"));
            }
        }
            
    }
}