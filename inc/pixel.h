#ifndef PIXEL_H
#define PIXEL_H

#include <cstdlib>
#include "debug.h"
typedef char color;

class pixel_interface {
  virtual unsigned hash() = 0;
};

class pixel : pixel_interface
{
public:
    inline virtual unsigned hash() { throw "thats bad" ;return -1; };
    virtual ~pixel(){};
    pixel(){};

protected:
};

#endif
