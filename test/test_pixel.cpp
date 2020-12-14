#include <catch2/catch.hpp>
#include "pixelRGB.h"

TEST_CASE("pixel stores values correctly", "[pixel]")
{
    char r = 1;
    char g = 2;
    char b = 3;
    pixelRGB p(r, g, b);
    REQUIRE(p.R() == r);
    REQUIRE(p.G() == g);
    REQUIRE(p.B() == b);
}