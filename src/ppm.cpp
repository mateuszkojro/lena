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
  parser #include "ppm_states.h"

      // // TODO add bounds checking
      // int to_number(std::string text) {
      //   // TODO check ujemne
      //   int result = 0;
      //   for (unsigned i = 0; i < text.size(); i++) {
      //     result += (text[i] - 48) * pow(10, text.size() - i - 1);
      //   }
      //   return result;
      // }

      // // TODO add bounds checking
      // int ascii_to_number(char znak) { return znak - 48; }

      // //! header
      // void header::read(char znak, parser<ppm> *machine) {
      //     printf("herer");
      //   if (znak == '#') {
      //     machine->change_state(new header_comment());
      //     delete this;
      //   } else if (machine->parsing_target_.mode_ == mode(none)) {
      //     machine->change_state(new header_format());
      //     delete this;
      //   } else {
      //     machine->change_state(new header_dimentions());
      //     delete this;
      //   }
      // }

      // //! header comment

      // //! header format
      // void header_format::read(char znak, parser<ppm> *machine) {
      //   if (ascii_to_number(znak) == 6) {
      //     machine->parsing_target_.mode_ = mode(binary);
      //   } else {
      //     machine->parsing_target_.mode_ = mode(ascii);
      //   }
      //   machine->change_state(new header_dimentions());
      //   delete this;
      // }

      // //! header dimentions
      // // TODO conttoll state enumem
      // void header_dimentions::read(char znak, parser<ppm> *machine) {
      //   // TODO czy ja powinienem sprawdzac tutaaj czy jest liczba?
      //   if (is_digit(znak)) {
      //     machine->buffer_ += znak;
      //   } else if (machine->parsing_target_.size_x_ == 0) {
      //     machine->parsing_target_.size_x_ = to_number(machine->buffer_);
      //     machine->buffer_ = "";
      //   } else if (machine->parsing_target_.size_y_ == 0) {
      //     machine->parsing_target_.size_y_ = to_number(machine->buffer_);
      //     machine->buffer_ = "";
      //   } else if (machine->parsing_target_.size_x_ == 0) {
      //     machine->parsing_target_.color_depth_ =
      //     to_number(machine->buffer_); machine->buffer_ = "";
      //   } else {
      //     //TODO nie podoba mi sie to dawanie znaku w tym mijescu
      //     machine->change_state(new number<ppm>());
      //     delete this;
      //   }
      // }
#include "ppm_states.h"

      // // TODO add bounds checking
      // int to_number(std::string text) {
      //   // TODO check ujemne
      //   int result = 0;
      //   for (unsigned i = 0; i < text.size(); i++) {
      //     result += (text[i] - 48) * pow(10, text.size() - i - 1);
      //   }
      //   return result;
      // }

      // // TODO add bounds checking
      // int ascii_to_number(char znak) { return znak - 48; }

      // //! header
      // void header::read(char znak, parser<ppm> *machine) {
      //     printf("herer");
      //   if (znak == '#') {
      //     machine->change_state(new header_comment());
      //     delete this;
      //   } else if (machine->parsing_target_.mode_ == mode(none)) {
      //     machine->change_state(new header_format());
      //     delete this;
      //   } else {
      //     machine->change_state(new header_dimentions());
      //     delete this;
      //   }
      // }

      // //! header comment

      // //! header format
      // void header_format::read(char znak, parser<ppm> *machine) {
      //   if (ascii_to_number(znak) == 6) {
      //     machine->parsing_target_.mode_ = mode(binary);
      //   } else {
      //     machine->parsing_target_.mode_ = mode(ascii);
      //   }
      //   machine->change_state(new header_dimentions());
      //   delete this;
      // }

      // //! header dimentions
      // // TODO conttoll state enumem
      // void header_dimentions::read(char znak, parser<ppm> *machine) {
      //   // TODO czy ja powinienem sprawdzac tutaaj czy jest liczba?
      //   if (is_digit(znak)) {
      //     machine->buffer_ += znak;
      //   } else if (machine->parsing_target_.size_x_ == 0) {
      //     machine->parsing_target_.size_x_ = to_number(machine->buffer_);
      //     machine->buffer_ = "";
      //   } else if (machine->parsing_target_.size_y_ == 0) {
      //     machine->parsing_target_.size_y_ = to_number(machine->buffer_);
      //     machine->buffer_ = "";
      //   } else if (machine->parsing_target_.size_x_ == 0) {
      //     machine->parsing_target_.color_depth_ =
      //     to_number(machine->buffer_); machine->buffer_ = "";
      //   } else {
      //     //TODO nie podoba mi sie to dawanie znaku w tym mijescu
      //     machine->change_state(new number<ppm>());
      //     delete this;
      //   }
      // }
      _ppm p(all);
  std::cout << "liczba kolorow: " << p.get().count_colors() << std::endl;
  DEB(p.get().size());
};