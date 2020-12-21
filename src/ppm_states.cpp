#include "ppm_states.h"

void ppm_header::read(char znak, ppm_parser *machine) {
  printf("header: %c\n",znak);
  if (znak == '#') {
    machine->change_state(new header_comment());
    delete this;
  } else if (machine->get_mode() == file_type(none)) {
    machine->change_state(new header_format());
    delete this;
  } else {
    machine->change_state(new header_dimentions());
    delete this;
  }
}

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
    machine->set_mode(file_type(binary));
  } else {
    machine->set_mode(file_type(ascii));
  }
  machine->change_state(new header_dimentions());
  delete this;
}

// TODO conttoll state enumem
void header_dimentions::read(char znak, ppm_parser *machine) {
  // TODO czy ja powinienem sprawdzac tutaaj czy jest liczba?
  if (helpers::is_digit(znak)) {
    machine->push_number_buffer(znak);
  } else if (!machine->did_read_size_x()) {
    machine->set_size_x(machine->get_number_buffer());
  } else if (!machine->did_read_size_y()) {
    machine->set_size_y(machine->get_number_buffer());
  } else if (!machine->did_read_color_depth()) {
    machine->set_color_depth(machine->get_number_buffer());
  } else {
    //TODO nie podoba mi sie to dawanie znaku w tym mijescu
    machine->push_number_buffer(znak);
    machine->change_state(new number<ppm>());
    delete this;
  }
}

