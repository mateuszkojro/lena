
//! OLD PARSER
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

};


//! old basic states

#if !defined(PPM_STATES)
#define PPM_STATES
#include "parser_ppm.h"


#endif // PPM_STATES


//! old parser ppm
#include "parser.h"
#include "ppm_states.h"
template <typename t>
class header : public state<t> {
public:
  header() : state<t>() {}
  virtual void read(char, parser<ppm> *);
};


class parser_ppm : public parser<ppm> {
public:
  parser_ppm(std::string text) {
    current_state_ = new header<ppm>();
    for (char i : text) {
      current_state_->read(i, this);
    }
  }
  inline void change_state(state<ppm> *new_state) {
    current_state_ = new_state;
  }
  ppm get() { return parsing_target_; }
  std::string buff_;
};


class header_format : public header<ppm> {
public:
  header_format() : header<ppm>() {}
  void read(char, parser<ppm> *);
};

class header_dimentions : public header<ppm> {
public:
  header_dimentions() : header() {}
  void read(char, parser<ppm> *);
};

class header_comment : public header<ppm> {
public:
  header_comment() : header() {}
void read(char znak, parser<ppm> *machine) {
  if (znak == '\n') {
    machine->change_state(new header());
    delete this;
  }
}
};