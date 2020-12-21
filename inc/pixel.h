
#ifndef PIXEL_H
#define PIXEL_H

#include <cstdio>
#include <cstdlib>
#include "debug.h"
typedef char color;

// klasa bazowa dla rewszty pixeli 

class pixel 
{
public:
    inline virtual unsigned hash() {return -1;};
    virtual ~pixel(){};
    pixel(){};

protected:
};

#endif