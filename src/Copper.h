#ifndef _COPPER_H_
#define _COPPER_H_

#include "Base.h"

/// @brief A  component
class Copper : public Base
{
public:
    static double copperGap;
    
    Copper() {};
    ~Copper() {};

    void operator=(const Copper& other);

};


#endif /* _COPPER_H_ */