#ifndef PPM_STATES_H
#define PPM_STATES_H

#include "ppm.h"
#include "ppm_parser.h"
#include "state_machine.h"
#include "states.h"
#include "helpers.h"

class ppm_header : public state_interface<ppm> {
public:
  void read(char, ppm_parser *) override;
};

class header_comment : public state_interface<ppm> {
public:
  void read(char, ppm_parser *) override;
};

class header_format : public state_interface<ppm> {
public:
  void read(char, ppm_parser *) override;
};

class header_dimentions : public state_interface<ppm> {
public:
  void read(char, ppm_parser *) override;
};
#endif // PPM_STATES_H
