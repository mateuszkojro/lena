#include "pgm.h"
#include "pgm_parser.h"

pgm::pgm(std::string path) : obraz() {
  mode_ = file_type(none);


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
  pgm_parser p(all);
  std::cout << "depth: " << p.get().color_depth_
            << "\nsize x: " << p.get().size_x_
            << "\nsize y: " << p.get().size_y_
            << "\nno colors: " << p.get().count_colors()
            << "\ncount pixles: " << p.get().count_pixels() << "\n";
  *this = p.get();
}

unsigned long pgm::count_colors() {
  // uzywamy unordered_map zeby stwworzyc hash table - umozliwia szybkie i
  // proste liczenie roznych kolorow
  std::unordered_map<unsigned, bool> n_colors;
  for (unsigned i = 0; i < pixels_.size(); i++) {
    // FIXME: zmienic hash
    n_colors[pixels_[i].hash()] = true;
  }
  return n_colors.size();
}
unsigned long pgm::count_pixels() { return pixels_.size(); }
