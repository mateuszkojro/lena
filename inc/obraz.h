#ifndef OBRAZ_H
#define OBRAZ_H

#include "debug.h"
#include "pixel.h"
#include "pixelRGB.h"
#include <string>
#include <unordered_map>
#include <vector>

// klasa obbraz
// - Uber klasa dla mniejszych klas
// - posiada buffor z obiektami @pixel
// - liczy kolory @count_colors
// -

class obraz;
int liczkolory(obraz);

class obraz {
public:
  obraz() {}

  unsigned long count_colors();
  unsigned long count_pixels();
  virtual ~obraz(){}
protected:
  std::vector<pixelRGB> buffer_;
  int size_x_;
  int size_y_;
};

#endif // OBRAZ_H
