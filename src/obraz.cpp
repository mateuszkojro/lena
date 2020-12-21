#include "obraz.h"
#include "debug.h"

int liczkolory(obraz o) { return o.count_colors(); }

unsigned long obraz::count_colors() {
  // uzywamy unordered_map zeby stwworzyc hash table - umozliwia szybkie i
  // proste liczenie roznych kolorow
  std::unordered_map<unsigned, bool> n_colors;
  for (unsigned i = 0; i < pixels_.size(); i++) {
    // FIXME: zmienic hash
    n_colors[pixels_[i].hash()] = true;
  }
  return n_colors.size();
}

unsigned long obraz::count_pixels() { return pixels_.size(); }