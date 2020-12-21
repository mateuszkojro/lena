#include "ppm.h"
#include <catch2/catch.hpp>

TEST_CASE("counting simple colors FULL", "[obraz]") {
  ppm p("../test/test_files/pixels_full.ppm");
  REQUIRE(p.count_colors() == 9);
}

TEST_CASE("counting simple pixels FULL", "[obraz]") {
  ppm p("../test/test_files/pixels_full.ppm");
  REQUIRE(p.count_pixels() == 9);
}

TEST_CASE("count pixels in full lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_pixels() == 512 * 512);
}

TEST_CASE("count colors in full lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_colors() == 52669);
}

TEST_CASE("count colors in big lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_colors() == 124317);
}
TEST_CASE("count pixels in big lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_pixels() == 1578 * 2048);
}