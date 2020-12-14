#include "parser.h"
#include "ppm.h"
#include <catch2/catch.hpp>

// TEST_CASE("counting simple colors", "[obraz]")
// {
//     ppm p("../test/test_files/only_pixels.ppm");
//     REQUIRE(p.count_colors() == 3);
// }

TEST_CASE("counting simple colors FULL", "[obraz]") {
  ppm p("../test/test_files/pixels_full.ppm");
  REQUIRE(p.count_colors() == 9);
}

TEST_CASE("counting simple pixels FULL", "[obraz]") {
  ppm p("../test/test_files/pixels_full.ppm");
  REQUIRE(p.count_pixels() == 9);
}

// TEST_CASE("count colors in lena", "[obraz]")
// {
//     ppm p("../test/test_files/lena.ppm");
//     REQUIRE(p.count_colors() == 52669);
// }

// TEST_CASE("count pixels in lena", "[obraz]")
// {
//     ppm p("../test/test_files/lena.ppm");
//     REQUIRE(p.count_pixels() == 512 * 512);
// }

TEST_CASE("count pixels in full lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_pixels() == 512 * 512);
}

TEST_CASE("count colors in full lena", "[obraz]") {
  ppm p("../test/test_files/lena_full.ppm");
  REQUIRE(p.count_colors() == 52669);
}
