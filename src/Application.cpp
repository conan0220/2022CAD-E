#include "Application.h"
#include "Text.h"
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"
#include "Math.h"
#include <stdio.h>

Application::Application()

{
    preProcessInputData();
    processSilkscreen();
    text::clearTextFile("../res/output.txt");
    outputToTxt<Assembly>("../res/output.txt", expandedAssembly, "assembly");
    // for (const Copper& expandedCopper : coppers)
    //     outputToTxt<Copper>("../res/output.txt", expandedCopper, "copper");
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
        for (double& i : data)
            math::roundToDecimal(i, 4);

        // identify the keyword of str
        if (text::isTargetInString(str, "line"))
        {
            Line dataTemp = Line(Point2D(data[0], data[1]), Point2D(data[2], data[3]));

            if (targetComponent == "assembly")
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));

            else if (targetComponent == "copper")
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
        }
        else if (text::isTargetInString(str, "arc"))
        {
            bool clockWiseTemp = !text::isTargetInString(str, "CCW");
            Arc dataTemp = Arc(Point2D(data[0], data[1]), Point2D(data[2], data[3]), Point2D(data[4], data[5]), clockWiseTemp);

            if (targetComponent == "assembly")
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));

            else if (targetComponent == "copper")
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
        }
        else if (text::isTargetInString(str, "coppergap"))
            Copper::copperGap = data[0];

        else if (text::isTargetInString(str, "copper"))
        {
            targetComponent = "copper";
            coppers.push_back(Copper());
        }
        else if (text::isTargetInString(str, "assemblygap"))
            Assembly::assemblyGap = data[0];

        else if (text::isTargetInString(str, "assembly"))
            targetComponent = "assembly";

        else if (text::isTargetInString(str, "silkscreenlen"))
            Silkscreen::silkscreenLen = data[0];
    }
}

void Application::processSilkscreen()
{
    setExpandedComponments();
    moveExpandedComponments();
}

/*
 * This function is used to set the expanded version of the assembly and coppers.
 */
void Application::setExpandedComponments()
{
    expandedAssembly = assembly;
    for (const Copper& copper : coppers)
        expandedCoppers.push_back(copper);
}

void Application::moveExpandedComponments()
{
    for (std::variant<Line, Arc>& element : expandedAssembly.lines_arcs)
    {
        if (std::holds_alternative<Line>(element))
        {
            Point2D normalVector = bg::extra::getNormalVector(std::get<Line>(element));
            normalVector.x(normalVector.x() * (-1));
            normalVector.y(normalVector.y() * (-1));
            bg::extra::standardization(normalVector);
            bg::extra::moveBoundary<Line>(std::get<Line>(element), assembly.assemblyGap, normalVector);
        }
        else if (std::holds_alternative<Arc>(element))
        {
            std::get<Arc>(element).radius += assembly.assemblyGap;
        }    
    }
}

/**
 * Output Componment to txt file. Ex. Assembly, Copper, Silkscreen.
 * @param filePath File path.
 * @return None.
 */
template <typename Componment>
void Application::outputToTxt(std::string filePath, const Componment& componment, const std::string componmentName)
{
    std::vector<std::string> text;

    text.push_back(componmentName);
    for (const std::variant<Line, Arc>& element : componment.lines_arcs)
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
            text.push_back("arc," + std::to_string(arc.begin.x()) + "," + std::to_string(arc.begin.y()) + "," + std::to_string(arc.end.x()) + "," + std::to_string(arc.end.y()) + "," + std::to_string(arc.center.x()) + "," + std::to_string(arc.center.y()) + "," + (arc.clockWise ? "CW" : "CCW"));
        }
    }

    text::writeFile(text, filePath, false);
}


