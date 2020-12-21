#ifndef STATES_H
#define STATES_H

#include "ppm.h"
#include "ppm_parser.h"
#include "state_machine.h"
#include "helpers.h"

template <class> class comment;
template <class> class whitespace;

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

#endif