#include "Application.h"
#include "Text.h"
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"
#include "Math.h"
#include <stdio.h>

Application::Application() {
    text::clearTextFile("../res/output.txt");
    preProcessInputData();
    processSilkscreen();
    outputToTxt<Assembly>("../res/output.txt", expandedAssembly, "assembly");
    for (Copper copper : expandedCoppers) {
        outputToTxt<Copper>("../res/output.txt", copper, "copper");
    }
}

/**
 * Read data and set it in specific component. For example, Assembly, Copper.
 * @return None.
 */
void Application::preProcessInputData() {
    std::vector<std::string> text = text::loadFile("../res/testing-data.txt");
    std::string targetComponent = "";  // current component we focus
    for (std::string str : text) {   // line by line 
        std::vector<double> data = text::extractNumeric(str);      //  numbers in the string
        for (double& i : data)
            i = math::getRoundToDecimal(i, 4);
        // identify the keyword of str
        if (text::isTargetInString(str, "line")) {
            Line dataTemp = Line(Point2D(data[0], data[1]), Point2D(data[2], data[3]));
            if (targetComponent == "assembly") {
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            } else if (targetComponent == "copper") {
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            }        
        } else if (text::isTargetInString(str, "arc")) {
            bool clockWiseTemp = !text::isTargetInString(str, "CCW");
            Arc dataTemp = Arc(Point2D(data[0], data[1]), Point2D(data[2], data[3]), Point2D(data[4], data[5]), clockWiseTemp);
            if (targetComponent == "assembly") {
                assembly.lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            } else if (targetComponent == "copper") {
                coppers.back().lines_arcs.push_back(std::variant<Line, Arc>(dataTemp));
            }    
        } else if (text::isTargetInString(str, "coppergap")) {
            Copper::GAP = data[0];
        } else if (text::isTargetInString(str, "copper")) {
            targetComponent = "copper";
            coppers.push_back(Copper());
        } else if (text::isTargetInString(str, "assemblygap")) {
            Assembly::GAP = data[0];
        } else if (text::isTargetInString(str, "assembly")) {
            targetComponent = "assembly";
        } else if (text::isTargetInString(str, "silkscreenlen")) {
            Silkscreen::LEN = data[0];
        }
    }
}

void Application::processSilkscreen() {
    setExpandedComponments();
    moveExpandedComponments();
}

// This function is used to set the expanded version of the assembly and coppers.
void Application::setExpandedComponments() {
    expandedAssembly = assembly;
    for (const Copper& copper : coppers)
        expandedCoppers.push_back(copper);
}

template <typename Componment>
void Application::moveExpandedComponment(Componment& componment, const double& distance) {
    Polygon polygon = componment.getPolygon();
    for (std::variant<Line, Arc>& element : componment.lines_arcs) {
        if (std::holds_alternative<Line>(element)) {
            Line& line = std::get<Line>(element);
            Point2D normalVector = bg::extra::getNormalVector(line);
            Point2D middle = bg::extra::getMiddle(line.first, line.second);
            bg::extra::movePoint2D(middle, 0.00001, normalVector);
            if (bg::within(middle, polygon)) {
                normalVector.x(normalVector.x() * (-1));
                normalVector.y(normalVector.y() * (-1));
            }
            bg::extra::moveBoundary<Line>(line, distance, normalVector); 
        } else if (std::holds_alternative<Arc>(element)) {
            Arc& arc = std::get<Arc>(element);
            Point2D posi = bg::extra::getMiddle(arc.getPositionOnArc(arc.angle / 2), arc.center);
            if (bg::within(posi, polygon)) {
                bg::extra::movePoint2D(arc.begin, distance, bg::extra::getDirectionVector(arc.begin, arc.center));
                bg::extra::movePoint2D(arc.end, distance, bg::extra::getDirectionVector(arc.end, arc.center));                
            } else {
                bg::extra::movePoint2D(arc.begin, distance, bg::extra::getDirectionVector(arc.center, arc.begin));
                bg::extra::movePoint2D(arc.end, distance, bg::extra::getDirectionVector(arc.center, arc.end));
            }
            arc.rewrite(arc.begin, arc.end, arc.center, arc.clockWise);
        }    
    }
}

// Expand the boundaries by the gap of componments.
void Application::moveExpandedComponments() {
    moveExpandedComponment<Assembly>(expandedAssembly, expandedAssembly.GAP);
    for (Copper& copper : expandedCoppers) {
        moveExpandedComponment<Copper>(copper, copper.GAP);
    }
}

/**
 * Output Componment to txt file. 
 * @param filePath File path.
 * @param componment Ex. Assembly, Copper, Silkscreen.
 * @param componmentName Ex. assembly, copper, silkscreen.
 * @return None.
 */
template <typename Componment>
void Application::outputToTxt(std::string filePath, const Componment& componment, const std::string& componmentName) {
    std::vector<std::string> text;
    text.push_back(componmentName);
    for (const std::variant<Line, Arc>& element : componment.lines_arcs) {
        if (std::holds_alternative<Line>(element)) {    // Element type is Line?
            Line line = std::get<Line>(element);
            double x1 = math::getRoundToDecimal(line.first.x(), 4);
            double x2 = math::getRoundToDecimal(line.second.x(), 4);
            double y1 = math::getRoundToDecimal(line.first.y(), 4);
            double y2 = math::getRoundToDecimal(line.second.y(), 4);
            text.push_back("line," + std::to_string(x1) + "," + std::to_string(y1) + "," + std::to_string(x2) + "," + std::to_string(y2));
        } else if (std::holds_alternative<Arc>(element)) {  // Element type is Arc?
            Arc arc = std::get<Arc>(element);
            double b_x = math::getRoundToDecimal(arc.begin.x(), 4);
            double e_x = math::getRoundToDecimal(arc.end.x(), 4);
            double c_x = math::getRoundToDecimal(arc.center.x(), 4);
            double b_y = math::getRoundToDecimal(arc.begin.y(), 4);
            double e_y = math::getRoundToDecimal(arc.end.y(), 4);
            double c_y = math::getRoundToDecimal(arc.center.y(), 4);
            text.push_back("arc," + std::to_string(b_x) + "," + std::to_string(b_y) + "," + std::to_string(e_x) + "," + std::to_string(e_y) + "," + std::to_string(c_x) + "," + std::to_string(c_y) + "," + (arc.clockWise ? "CW" : "CCW"));
        }
    }
    text::writeFile(text, filePath, false);
}

void Application::outputPoint2DToTxt(std::string filePath, const std::vector<Point2D>& points) {
    std::vector<std::string> text;
    text.push_back("points");     // points
    for (const Point2D& point : points) {
        double x = math::getRoundToDecimal(point.x(), 4);
        double y = math::getRoundToDecimal(point.y(), 4);
        text.push_back("point," + std::to_string(x) + "," + std::to_string(y));
    }
    text::writeFile(text, filePath, false);
}

