#ifndef PARSER_PPM_H
#define PARSER_PPM_H

// Klasa ppm_parser implementuje metody specyficznie potzrbne maszynie stanow do paroswania plikow ppm 

#include "helpers.h"
#include "obraz.h"
#include "pixelRGB.h"
#include "ppm.h"
#include "state_machine.h"
#include <new>
#include <string>
#include <vector>

typedef state_machine<ppm> ppm_parser;

template <> class state_machine<ppm> {
public:
  state_machine() = delete;
  state_machine(std::string);
  void change_state(state_interface<ppm> *);
  void set_mode(file_type);
  file_type get_mode();
  pixelRGB get_pixel_buffer();
  void push_pixel_buffer(int);

  int get_number_buffer();
  void push_number_buffer(char);

  bool is_pixel_ready();

  void add_pixel(pixelRGB);
  bool did_read_size_x();
  bool did_read_size_y();
  bool did_read_color_depth();
  void set_size_x(int);
  void set_size_y(int);
  void set_color_depth(int);
  ppm get();

protected:
  state_interface<ppm> *current_state_;
  std::vector<int> pixel_buffer_;
  std::string number_buffer_;
  ppm parsing_target_;
};

#endif