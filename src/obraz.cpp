#include "obraz.h"
#include "debug.h"
int liczkolory(obraz o) { return o.count_colors(); }

unsigned long obraz::count_colors() {
  // uzywamy unordered_map zeby stwworzyc hash table - umozliwia szybkie i
  // proste liczenie roznych kolorow
  std::unordered_map<unsigned, bool> n_colors;
  for (int i = 0; i < buffer_.size(); i++) {
    // FIXME: zmienic hash
    n_colors[buffer_[i].hash()] = true;
  }
  auto n = n_colors.size();
  return n_colors.size();
}

inline unsigned obraz::count_pixels() { return buffer_.size(); }