#ifndef PARSER_PPM_H
#define PARSER_PPM_H

#include "parser.h"

class header;

typedef parser<ppm> parser_ppm;

class header : public state<ppm> {
public:
  header():state<ppm>() {}
  virtual void read(char, parser_ppm *);
};

class header_format : public header {
public:
  header_format() : header() {}
  void read(char, parser_ppm *);
};

class header_dimentions : public header {
public:
  header_dimentions() : header() {}
  void read(char, parser_ppm *);
};

class header_comment : public header {
public:
  header_comment() : header() {}
  void read(char, parser_ppm *);
};

template <> class parser<ppm> : public parser_interface<ppm> {
public:
  parser(std::string text) {
    current_state_ = new header();
    for (char i : text) {
      current_state_->read(i, this);
    }
  }
  inline void change_state(state<ppm> *new_state) { current_state_ = new_state ;}
  ppm get() {return parsing_target_; }
};

#endif