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
    void moveExpandedComponments();

    template <typename Componment>
    void outputToTxt(std::string filePath, const Componment& componment, const std::string componmentName);

};

#endif /* _APPLICATION_H_ */