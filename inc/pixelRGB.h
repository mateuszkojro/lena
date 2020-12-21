#ifndef PIXELRGB_H
#define PIXELRGB_H

#include "pixel.h"

// TODO: wyjebac for production
typedef char color;

// klasa pixel rgb przechowywac bedzie kolory w formacie rgb

class pixelRGB  
{
public:
    pixelRGB() = delete;
    pixelRGB(color r, color g, color b): r(r), g(g), b(b) {}
    void set();
    virtual color R() { return r; }
    virtual color G() { return g; }
    virtual color B() { return b; }

    // jezeli |X| to moc zbioru X i y = a|X|^2 + b|X| + c gdzie a,b,c \in X
    // to y jednoznacznie okresla punkt w 3-w przestrzeni kolorow
    inline unsigned hash() { return (256 * 256 * r) + (256 * g) + b; }

protected:
    color r, g, b;
};

#endif