#include "ppm_states.h"

void ppm_header::read(char znak, ppm_parser *machine) {
  if (znak == '#') {
    machine->change_state(new header_comment());
    delete this;
  } else if (machine->get_mode() == mode(none)) {
    machine->change_state(new header_format());
    delete this;
  } else {
    machine->change_state(new header_dimentions());
    delete this;
  }
}


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


void header_comment::read(char znak, ppm_parser *machine) {
  if (znak == '\n') {
    machine->push_number_buffer(znak);
    machine->change_state(new ppm_header());
    delete this;
  }
}

//TODO kto sprawdza czy poprzedni byl 'P'
void header_format::read(char znak, ppm_parser *machine) {
  if (znak == '6') {
    machine->set_mode(mode(binary));
  } else {
    machine->set_mode(mode(ascii));
  }
  machine->change_state(new header_dimentions());
  delete this;
}

// TODO conttoll state enumem
void header_dimentions::read(char znak, ppm_parser *machine) {
  // TODO czy ja powinienem sprawdzac tutaaj czy jest liczba?
  if (helpers::is_digit(znak)) {
    machine->push_number_buffer(znak);
  } else if (machine->parsing_target_.size_x_ == 0) {
    machine->set_size_x(machine->get_number_buffer());
  } else if (machine->parsing_target_.size_y_ == 0) {
    machine->set_size_y(machine->get_number_buffer());
  } else if (machine->parsing_target_.color_depth_ == 0) {
    machine->set_color_depth(machine->get_number_buffer());
  } else {
    //TODO nie podoba mi sie to dawanie znaku w tym mijescu
    machine->change_state(new number<ppm>());
    delete this;
  }
}
