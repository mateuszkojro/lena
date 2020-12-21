#include "ppm.h"
#include "debug.h"
#include "ppm_parser.h"

ppm::ppm(std::string path) : obraz() {
  std::fstream file;
  std::string all;
  all.reserve(512 * 512);

  file.open(path, std::ios::in);

  std::string input;
  // TODO make it allocate less
  while (std::getline(file, input)) {
    input += "\n";
    all += input;
  }
  ppm_parser p(all);
  *this = p.get();
};