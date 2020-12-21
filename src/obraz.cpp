#include "obraz.h"
#include "debug.h"

obraz::obraz() {
  size_x_ = 0;
  size_y_ = 0;
  color_depth_ = 0;
}

int liczkolory(obraz o) { return o.count_colors(); }
