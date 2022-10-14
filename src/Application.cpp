#include "Application.h"
#include "Text.h"
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"

Application::Application()
{
    // read data and set in specific component
    preProcessData();
    std::cout << bg::extra::getDegree(assembly.arcs[0].center, assembly.arcs[0].begin);
}

/*
 * Description: read data and set it in specific component
 * Parameters: None
 */
void Application::preProcessData()
{
    std::vector<std::string> text = loadFile("../res/testing-data.txt");
    std::string targetComponent = "";  // present component we focus
    for (std::string str : text)    // line by line
    {
        std::vector<double> data = getDataFromString(str);      //  numbers in the string

        // identify the keyword of str
        if (isTargetInString(str, "line"))
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
        else if (isTargetInString(str, "arc"))
        {
            bool clockWiseTemp = !isTargetInString(str, "CCW");
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
        else if (isTargetInString(str, "coppergap"))
        {
            Copper::copperGap = data[0];
        }
        else if (isTargetInString(str, "copper"))
        {
            targetComponent = "copper";
            coppers.push_back(Copper());
        }
        else if (isTargetInString(str, "assemblygap"))
        {
            Assembly::assemblyGap = data[0];
        }
        else if (isTargetInString(str, "assembly"))
        {
            targetComponent = "assembly";
        }
        else if (isTargetInString(str, "silkscreenlen"))
        {
            Silkscreen::silkscreenLen = data[0];
        }
    }
}