#ifndef PGM_H
#define PGM_H

#include "debug.h"
#include "obraz.h"
#include "pixelGrayscale.h"
#include <fstream>
#include <iostream>
#include <string>

class pgm : public obraz {
public:
  pgm():obraz() {}
  // TODO initiaaalize vars
  pgm(std::string file);

  // private:
  // TODO fix this name
  // file_type mode_;
  std::vector<pixelGrayscale> pixels_;
  unsigned long count_colors();
  unsigned long count_pixels();
  ~pgm(){}
};

#endif