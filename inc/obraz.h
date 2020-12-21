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

// nie ma potrzeby definiowania konstruktora kopiujacaego ani operatora ==
// poniewaz nie mamy elementow ktore wymagaja specjalnego traktowania podczas
// kopiowania
class obraz {
public:
  obraz() {}

  unsigned long count_colors();
  unsigned long count_pixels();
  virtual ~obraz() {}

// protected:
  std::vector<pixel> pixels_;

  unsigned size_x_; 
  unsigned size_y_;
  unsigned color_depth_;
};

#endif // OBRAZ_H
