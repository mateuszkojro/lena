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

  virtual unsigned long count_colors();
  unsigned long count_pixels();
  virtual ~obraz() {}

// protected:
  std::vector<pixelRGB> pixels_;
  // FIXME not using them
  int size_x_; 
  int size_y_;
  int max_color_;
};

#endif // OBRAZ_H
