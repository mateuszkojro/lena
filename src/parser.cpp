#include "parser.h"
#include "debug.h"

inline bool is_number(char znak) { return (znak >= 48 && znak <= 57); }

inline bool is_comment(char znak) { return (znak == '#'); }
inline bool is_whitespace(char znak) {
  return (znak == '\t' || znak == ' ' || znak == '\n');
}

// todo add bounds checking
inline int to_number(std::string text) {
  int result = 0;
  for (int i = 0; i < text.size(); i++) {
    result += (text[i] - 48) * pow(10, text.size() - i - 1);
  }
  return result;
}

// todo add bounds checking
inline int to_number(char znak) { return znak - 48; }

// base state
state::state() {}
state::state(char znak) { DEBC(znak, "state"); }
state *state::read(char znak, std::vector<char> &out) {
  ERR("WTF");
  exit(123);
}

state *comment::read(char znak, std::vector<char> &out) {
  DEBC(znak, ":err char");
  if (znak == '\n' || znak == '\0') {
    return new whitespace(znak);
  }
  return this;
}

state *whitespace::read(char znak, std::vector<char> &out) {
  if (is_number(znak)) {
    return new number(znak);
  } else if (is_comment(znak)) {
    return new comment(znak);
  }
  return this;
}

number::number(char znak) : state() {
  DEBC(znak, "number");
  buff_ = znak;
}

state *number::read(char znak, std::vector<char> &out) {
  if (is_number(znak)) {
    buff_ += znak;
  } else {
    if (to_number(buff_) < 256 && to_number(buff_) >= 0) {

      DEBC(to_number(buff_), "wartosc liczbowa");
      out.push_back(to_number(buff_));
      buff_ = "";
    } else {
      std::cout << buff_ << "==" << to_number(buff_) << std::endl;
      ERR("bad value");
    }
    if (is_comment(znak)) {
      return new comment(znak);
    } else if (is_whitespace(znak)) {
      return new whitespace(znak);
    }
  }
  return this;
}

parser::parser(std::string text) {
  buffer_.reserve(512 * 512 * sizeof(char));
  current_state_ = new header('0');
  unsigned long itr = 0;
  for (char i : text) {
    current_state_ = current_state_->read(i, buffer_);
  }
}

std::vector<pixelRGB> parser::get() {
  // todo check what when too many or too little
  std::vector<pixelRGB> result;
  for (int i = 0; i < buffer_.size(); i += 3) {
    char r = buffer_[i];
    char g = buffer_[i + 1];
    char b = buffer_[i + 2];
    result.push_back(pixelRGB(r, g, b));
  }
  return result;
}

parser::~parser() { delete current_state_; }

state *header::read(char znak, std::vector<char> &out) {
  if (znak == '#') {
    return new header_comment(znak);
  } else if (format_.size() < 2) {
    return new header_format(znak);
  } else {
    return new header_dimentions(znak);
  }
  return this;
}

state *header_comment::read(char znak, std::vector<char> &out) {
  if (znak == '\n') {
    return new header(znak);
  }
  return this;
}

state *header_format::read(char znak, std::vector<char> &out) {
  if (format_.size() == 1 && to_number(znak) < 6) {
    format_ += znak;
    is_binary_ = to_number(znak) > 3;
    return new header_dimentions(znak);
  }
  return this;
}

state *header_dimentions::read(char znak, std::vector<char> &out) {
  if (dimentions_.size() < 4 && is_number(znak)) {
    buffer_ += znak;
  } else if (dimentions_.size() < 4) {
    dimentions_.push_back(to_number(buffer_));
    buffer_ = "";
  } else {
    return new number(znak);
  }
  return this;
}