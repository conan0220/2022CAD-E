#include "Application.h"
#include "Text.h"

Application::Application()
{
    // read data and set in specific componment
    preProcessData();
}

/*
 * Description: read data and set in specific componment
 * Parameters: None
 */
void Application::preProcessData()
{
    std::vector<std::string> text = loadFile("../res/testing-data.txt");
    for (std::string str : text)    // line by line
    {
        std::vector<double> data = getDataFromString(str);      //  numbers in the string

        // identify the keyword of str
        if (isTargetInString(str, "line"))
        {
            // store the data
        }
        else if (isTargetInString(str, "arc"))
        {
            // store the data
        }
        else if (isTargetInString(str, "assemblygap"))
        {
            // store the data
        }
        else if (isTargetInString(str, "coppergap"))
        {
            // store the data
        }
        else if (isTargetInString(str, "silkscreenlen"))
        {
            // store the data
        }
        else if (isTargetInString(str, "assembly"))
        {
            // store the data
        }
        else if (isTargetInString(str, "copper"))
        {
            // store the data
        }
        
    }
}