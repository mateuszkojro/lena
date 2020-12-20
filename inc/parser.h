#ifndef PARSER_H
#define PARSER_H
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "debug.h"
#include "pixel.h"
#include "pixelRGB.h"
#include "ppm.h"

template <typename> class state;
template <typename> class number;
template <typename> class comment;
template <typename> class whitespace;
template <typename> class parser;

//! HELPERS
inline bool is_digit(char znak);
inline bool is_comment(char znak);
inline bool is_whitespace(char znak);
inline int to_number(std::string text);
inline int ascii_to_number(char znak);

template <typename t> class parser_interface {
public:
  friend class state<t>;
  t parsing_target_;
  std::string buffer_;
  state<t> *current_state_;
  std::vector<int> pixel_buffer_;
  inline virtual void change_state(state<t> *new_state) = 0;
  inline virtual t get() = 0;
  virtual ~parser_interface<t>(){};
};

//! STATES
template <typename t> class parser {
public:
  friend class state<t>;
  t parsing_target_;
  // HAACK well thats a hack if i ever seen one
  std::string buffer_;
  std::vector<int> pixel_buffer_;
  inline void change_state(state<t> *new_state) { current_state_ = new_state; }
  t get() { return parsing_target_; }
  ~parser() { delete current_state_; }
  state<t> *current_state_;

protected:
  // parser(std::string);
  parser();
};

template <typename t> class state {
public:
  void read(char, parser<t> *) {
    // TODO remove me
    ERR("WTF");
    exit(123);
  }

protected:
  state() {}
  virtual ~state() {}
};

template <typename t> class number : public state<t> {
public:
  number() : state<t>() {}

  void read(char znak, parser<t> *machine) {
    if (is_digit(znak)) {
      machine->buff_ += znak;
    } else {
      machine->pixel_buffer_.push_back(to_number(machine->buff_));
      if (machine->pixel_buffer_.size() == 3) {
        // HAACK well kazde ddzialaenie ma swoje konsekwencje
        // ale bez lepszych pomyslow poki co

        int r = machine->pixel_buffer_[0];
        int g = machine->pixel_buffer_[1];
        int b = machine->pixel_buffer_[1];
        machine->pixel_buffer_.clear();
        machine->parsing_target_.buffer_.push_back(pixelRGB(r, g, b));
      }
      if (is_comment(znak)) {
        machine->change_state(new comment<t>());
        delete this;
      } else if (is_whitespace(znak)) {
        machine->change_state(new whitespace<t>());
        delete this;
      }
    }
  }
};

template <typename t> class comment : public state<t> {
public:
  comment() : state<t>() {}
  void read(char znak, parser<t> *machine) {
    if (znak == '\n' || znak == '\0') {
      machine->change_state(new whitespace<t>());
      delete this;
    }
  }
};

template <typename t> class whitespace : public state<t> {
public:
  whitespace() : state<t>() {}
  void read(char znak, parser<t> *machine) {
    if (is_digit(znak)) {
      machine->change_state(new number<t>(znak));
      delete this;
    } else if (is_comment(znak)) {
      machine->change_state(new comment<t>());
      delete this;
    }
  }
};

#endif