#include "ppm.h"
#include "debug.h"
#include "parser.h"

ppm::ppm(std::string path) : obraz() {
  std::fstream file;

  std::string all;

  file.open(path, std::ios::in);

  std::string input;
  while (std::getline(file, input)) {
    input += "\n";
    all += input;
  }
  parser p(all);
  buffer_ = p.get();
  DEB(p.get().size());
};