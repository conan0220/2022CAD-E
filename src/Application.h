#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "Assembly.h"
#include "Copper.h"
#include "Silkscreen.h"

class Application {
public:
    Application();
    ~Application() {}
    
    template <typename Componment>
    static void outputToTxt(std::string filePath, const Componment& componment, const std::string& componmentName);
    static void outputPoint2DToTxt(std::string filePath, const std::vector<Point2D>& points);

    Assembly assembly;
    std::vector<Copper> coppers;
    Assembly expandedAssembly;
    std::vector<Copper> expandedCoppers;
    std::vector<Silkscreen> silkscreens;

private:
    void preProcessInputData();
    void processSilkscreen();
    void setExpandedComponments();
    template <typename Componment>
    void moveExpandedComponment(Componment& componment, const double& distance);
    void moveExpandedComponments();
};

#endif /* _APPLICATION_H_ */