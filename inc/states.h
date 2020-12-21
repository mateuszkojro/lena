#ifndef STATES_H
#define STATES_H

#include "helpers.h"
#include "ppm.h"
#include "ppm_parser.h"
#include "state_machine.h"
#include <cstdio>

template <class> class comment;
template <class> class whitespace;
template <class> class whitespace;
template <class> class header_format;
template <class> class header_dimentions;
template <class> class header_comment;
template <class> class header;


template <typename t> class number : public state_interface<t> {
public:
  void read(char znak, state_machine<ppm> *machine) {
    if (helpers::is_digit(znak)) {
      machine->push_number_buffer(znak);
    } else {
      machine->push_pixel_buffer(machine->get_number_buffer());
      if (machine->is_pixel_ready()) {
        machine->add_pixel(machine->get_pixel_buffer());
      }
      if (helpers::is_comment(znak)) {
        machine->change_state(new comment<t>());
        delete this;
      } else if (helpers::is_whitespace(znak)) {
        machine->change_state(new whitespace<t>());
        delete this;
      }
    }
  }
};

template <typename t> class comment : public state_interface<t> {
public:
  comment() : state_interface<t>() {}
  void read(char znak, state_machine<t> *machine) {
    if (znak == '\n' || znak == '\0') {
      machine->change_state(new whitespace<t>());
      delete this;
    }
  }
};

template <typename t> class whitespace : public state_interface<t> {
public:
  whitespace() : state_interface<t>() {}
  void read(char znak, state_machine<t> *machine) {
    if (helpers::is_digit(znak)) {
      machine->push_number_buffer(znak);
      machine->change_state(new number<t>());
      delete this;
    } else if (helpers::is_comment(znak)) {
      machine->change_state(new comment<t>());
      delete this;
    }
  }
};

template <typename t> class header : public state_interface<t> {
public:
  void read(char znak, state_machine<t> * machine){
  printf("header: %c\n",znak);
  if (znak == '#') {
    machine->change_state(new header_comment<t>());
    delete this;
  } else if (machine->get_mode() == file_type(none)) {
    machine->change_state(new header_format<t>());
    delete this;
  } else {
    machine->change_state(new header_dimentions<t>());
    delete this;
  }
}
};

template <typename t> class header_comment : public state_interface<t> {
public:
  void read(char znak, state_machine<t> *machine){
  if (znak == '\n') {
    machine->push_number_buffer(znak);
    machine->change_state(new header<t>());
    delete this;
  }
}
};

//TODO kto sprawdza czy poprzedni byl 'P'
template <typename t> class header_format : public state_interface<t> {
public:
  void read(char znak, state_machine<t> *machine) {
    if (znak == '6') {
      machine->set_mode(file_type(binary));
    } else {
      machine->set_mode(file_type(ascii));
    }
    machine->change_state(new header_dimentions<t>());
    delete this;
  }
};

template <typename t> class header_dimentions : public state_interface<t> {
public:
  void read(char znak, state_machine<t> *machine) {
    // TODO czy ja powinienem sprawdzac tutaaj czy jest liczba?
    if (helpers::is_digit(znak) && !machine->did_read_color_depth()) {
      machine->push_number_buffer(znak);
    } else if (!machine->did_read_size_x()) {
      machine->set_size_x(machine->get_number_buffer());
    } else if (!machine->did_read_size_y()) {
      machine->set_size_y(machine->get_number_buffer());
    } else if (!machine->did_read_color_depth()) {
      machine->set_color_depth(machine->get_number_buffer());
    } else {
      machine->push_number_buffer(znak);
      machine->change_state(new number<t>());
      delete this;
    }
  }
};
#endif