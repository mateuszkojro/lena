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
  unsigned long count_colors() {
    TIME_START(count);
    // uzywamy unordered_map zeby stwworzyc hash table - umozliwia szybkie i
    // proste liczenie roznych kolorow
    std::unordered_map<unsigned, bool> n_colors;

    for (int i = 0; i < buffer_.size(); i++) {
      n_colors[buffer_[i].hash()] = true;
    }
    int colors = n_colors.size();
    TIME_STOP(count, "counting");
    return n_colors.size();
  }
};

#endif // PPM_H