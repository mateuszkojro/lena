#ifndef PPM_H
#define PPM_H
#include "obraz.h"
#include <fstream>
#include <iostream>
#include <string>

enum file_type {
  none,
  ascii,
  binary
};

class ppm : public obraz {
public:
  ppm(){} 
  // TODO initiaaalize vars
  ppm(std::string file);

// private:
  //TODO fix this name 
  file_type mode_;

};

#endif // PPM_H