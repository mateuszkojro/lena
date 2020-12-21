#ifndef PIXEL_GRAYSCALE
#define PIXEL_GRAYSCALE

#include "pixel.h"
class pixelGrayscale : public pixel {
public:
  pixelGrayscale(int color):pixel(), g(color) {}
    pixelGrayscale() = delete;
    void set();
    virtual color Color() { return g; }

    // jezeli |X| to moc zbioru X i y = a|X|^2 + b|X| + c gdzie a,b,c \in X
    // to y jednoznacznie okresla punkt w 3-w przestrzeni kolorow
    inline unsigned hash() override { return (256 * 256 * g) + (256 * g) + g; }

protected:
    color g;
};

#endif