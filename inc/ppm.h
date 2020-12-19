#ifndef PPM_H
#define PPM_H
#include "obraz.h"
#include <fstream>
#include <iostream>
#include <string>

class ppm : public obraz {
public:
  ppm() = delete;
  ppm(std::string file);
};

#endif // PPM_H