#ifndef _ASSEMBLY_H_
#define _ASSEMBLY_H_

#include "Base.h"

class Assembly : public Base {
public:
  
    Assembly() {}
    ~Assembly() {}

    void operator=(const Assembly& other);

    static double assemblyGap;
};


#endif /* _ASSEMBLY_H_ */