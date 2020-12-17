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

  unsigned long virtual count_colors();
  unsigned virtual count_pixels();

protected:
  // MAYBE: czy robic to jako vector czy zostawic raw array
  std::vector<pixelRGB> buffer_;
};

#endif // OBRAZ_H
