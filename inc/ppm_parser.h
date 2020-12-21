#ifndef PARSER_PPM_H
#define PARSER_PPM_H

#include "pixelRGB.h"
#include "state_machine.h"
#include "helpers.h"
#include "ppm.h"
#include <string>
#include <vector>

typedef state_machine<ppm> ppm_parser;

template<>
class state_machine<ppm>{
public:
  friend class ppm;
  void change_state(state_interface<ppm>*);
  void set_mode(mode);
  mode get_mode();
  pixelRGB get_pixel_buffer();
  void push_pixel_buffer(int);

  int get_number_buffer();
  void push_number_buffer(char);

  bool is_pixel_ready();

  void add_pixel(pixelRGB);

  void set_size_x(int);
  void set_size_y(int);
  void set_color_depth(int);

protected:
  state_interface<ppm>* current_state_;
  std::vector<int> pixel_buffer_;
  std::string number_buffer_;
  ppm parsing_target_;
};

#endif