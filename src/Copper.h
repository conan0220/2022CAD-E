#ifndef _COPPER_H_
#define _COPPER_H_

#include "Base.h"

/// @brief A  component
class Copper : public Base {
public:
    Copper() {};
    ~Copper() {};

    void operator=(const Copper& other);

    static double copperGap;
};


#endif /* _COPPER_H_ */