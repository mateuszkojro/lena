#ifndef PPM_H
#define PPM_H

#include "obraz.h"
#include <fstream>
#include <iostream>
#include <string>
#include "debug.h"
#include "pgm_parser.h"

int liczkolory(obraz);

class ppm : public obraz {
public:
  ppm():obraz(){} 
  // TODO initiaaalize vars
  ppm(std::string file);

// private:
  //TODO fix this name 
  // file_type mode_;
  std::vector<pixelRGB> pixels_;
  unsigned long count_colors();
  unsigned long count_pixels();
  ~ppm(){}
};

#endif // PPM_H