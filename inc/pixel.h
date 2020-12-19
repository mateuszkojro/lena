#ifndef PIXEL_H
#define PIXEL_H

#include <cstdlib>
#include "debug.h"
typedef char color;

class pixel
{
public:
    pixel(){};
    inline virtual unsigned hash() { ERR("reading in virtual pixel"); return 1; };
    virtual ~pixel(){};
};

#endif
