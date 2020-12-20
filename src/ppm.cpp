#include "ppm.h"
#include "debug.h"
#include "parser.h"
#include "parser_ppm.h"

ppm::ppm(std::string path) : obraz() {
  std::fstream file;

  std::string all;

  file.open(path, std::ios::in);

  std::string input;
  // TODO make it allocate less
  while (std::getline(file, input)) {
    input += "\n";
    all += input;
  }
  parser_ppm p(all);
  std::cout << "liczba kolorow: " << p.get().count_colors() << std::endl;
  DEB(p.get().size());
};