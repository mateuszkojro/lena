#ifndef PPM_H
#define PPM_H
#include "obraz.h"
#include <fstream>
#include <iostream>
#include <string>

enum mode {
  none,
  ascii,
  binary
};

class ppm : public obraz {
public:
  ppm(){} 
  // TODO initiaaalize vars
  ppm(std::string file);

  unsigned long count_colors() { std::cout << "ppm count colors\n"; }
// private:
  //TODO fix this name 
  mode mode_;
  unsigned size_x_, size_y_,
      color_depth_;

};

#endif // PPM_H