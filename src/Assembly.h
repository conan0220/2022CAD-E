#ifndef _ASSEMBLY_H_
#define _ASSEMBLY_H_

#include "Base.h"

class Assembly : public Base
{
public:
    static double assemblyGap;
  
    Assembly() {}
    ~Assembly() {}

    void operator=(const Assembly& other);

};


#endif /* _ASSEMBLY_H_ */