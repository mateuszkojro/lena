#ifndef PARSER_PGM_H
#define PARSER_PGM_H

// Klasa pgm_parser implementuje metody specyficznie potzrbne maszynie stanow do
// paroswania plikow pgm implemenntacja oparta jest na rozpisaniu stanow w
// jakich mozm4ey sie znajdowac i przejsc pomiedzyu nimi
// dzieki zastosowaniu templatow I polimorfizmu nasze stany moga zostac poraz kolejny jak np podczas pisania klasy parser_ppm

#include "helpers.h"
#include "obraz.h"
#include "pixelRGB.h"
#include "pgm.h"
#include "state_machine.h"
#include "pixelGrayscale.h"
#include <new>
#include <string>
#include <vector>

typedef state_machine<pgm> pgm_parser;

template <>
class state_machine<pgm>{ 
public:
  state_machine() = delete;
  state_machine(std::string);
  void change_state(state_interface<pgm> *);
  void set_mode(file_type);
  file_type get_mode();
  pixelGrayscale get_pixel_buffer();
  void push_pixel_buffer(int);

  int get_number_buffer();
  void push_number_buffer(char);

  bool is_pixel_ready();

  void add_pixel(pixelGrayscale);
  bool did_read_size_x();
  bool did_read_size_y();
  bool did_read_color_depth();
  void set_size_x(int);
  void set_size_y(int);
  void set_color_depth(int);
  pgm get();

protected:
  state_interface<pgm> *current_state_;
  std::vector<int> pixel_buffer_;
  std::string number_buffer_;
  pgm parsing_target_;
};

#endif
