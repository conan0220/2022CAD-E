#ifndef _APPLICATION_H_
#define _APPLICATION_H_
#include "Assembly.h"
#include "Copper.h"

class Application
{
public:
    Application();
    ~Application() {}

    Assembly assembly;
    std::vector<Copper> coppers;

private:
    void preProcessData();

};

#endif /* _APPLICATION_H_ */