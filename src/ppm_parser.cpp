#include "ppm_parser.h"
#include "helpers.h"
#include "pixelRGB.h"
#include "ppm.h"
#include "states.h"
#include "state_machine.h"
#include <cstdio>
#include <string>


state_machine<ppm>::state_machine(std::string text) {
  current_state_ = new header<ppm>();
  for (char znak : text) {
    current_state_->read(znak,this);
  }
}

void ppm_parser::change_state(state_interface<ppm> *new_state) {
  current_state_ = new_state;
}

void ppm_parser::set_mode(file_type new_mode) {
  parsing_target_.mode_ = new_mode;
}
file_type ppm_parser::get_mode() { return parsing_target_.mode_; }

pixelRGB ppm_parser::get_pixel_buffer() {
  pixelRGB temp(pixel_buffer_[0], pixel_buffer_[1], pixel_buffer_[2]);
  pixel_buffer_.clear();
  return temp;
}

void ppm_parser::push_pixel_buffer(int value) {
  // if (value < parsing_target_.color_depth_ && value > 0) {
    pixel_buffer_.push_back(value);
  // }
}

int ppm_parser::get_number_buffer() {
  int temp = helpers::to_number(number_buffer_);
  // printf("number(int): %d\n",temp);
  number_buffer_.clear();
  return temp;
}

void ppm_parser::push_number_buffer(char znak) {
  if (helpers::is_digit(znak))
    number_buffer_.push_back(znak);
}

bool ppm_parser::is_pixel_ready() {
  if (pixel_buffer_.size() == 3)
    return true;
  else
    return false;
}

void ppm_parser::add_pixel(pixelRGB pixel) {
  parsing_target_.pixels_.push_back(pixel);
}

void ppm_parser::set_size_x(int size_x) { parsing_target_.size_x_ = size_x; }
void ppm_parser::set_size_y(int size_y) { parsing_target_.size_y_ = size_y; }
void ppm_parser::set_color_depth(int color_depth) {
  parsing_target_.color_depth_ = color_depth;
}

bool ppm_parser::did_read_size_x() { return (parsing_target_.size_x_ != 0); }
bool ppm_parser::did_read_size_y() { return (parsing_target_.size_y_ != 0); }
bool ppm_parser::did_read_color_depth() {
  return (parsing_target_.color_depth_ != 0);
}

ppm ppm_parser::get() {
  return parsing_target_;
}