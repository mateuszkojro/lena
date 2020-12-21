#ifndef OBRAZ_H
#define OBRAZ_H

#include "debug.h"
#include "pixel.h"
#include "pixelRGB.h"
#include <string>
#include <unordered_map>
#include <vector>

// przechowujemy jakiego rodzjau plik czytamy
enum file_type { none, ascii, binary };
class obraz;
int liczkolory(obraz);

// nie ma potrzeby definiowania konstruktora kopiujacaego ani operatora ==
// poniewaz nie mamy elementow ktore wymagaja specjalnego traktowania podczas
// kopiowania
class obraz {
public:
  obraz();

  virtual unsigned long count_colors(){return -1;}
  virtual unsigned long count_pixels(){return -1;}
  virtual ~obraz() {}

  // protected:

  file_type mode_;
  unsigned size_x_;
  unsigned size_y_;
  unsigned color_depth_;
};

#endif // OBRAZ_H
