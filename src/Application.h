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

    Assembly expandedAssembly;
    std::vector<Copper> expandedCoppers;

    std::vector<Silkscreen> silkscreens;

private:
    void preProcessInputData();
    void processSilkscreen();
    void setExpandedComponments();

    void outputToTxt(std::string filePath);

};

#endif /* _APPLICATION_H_ */