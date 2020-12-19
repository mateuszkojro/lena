#include "parser.h"
#include "debug.h"

 bool is_number(char znak) { return (znak >= 48 && znak <= 57); }
 bool is_comment(char znak) { return (znak == '#'); }
 bool is_whitespace(char znak) {
  return (znak == '\t' || znak == ' ' || znak == '\n');
}


// TODO add bounds checking
 int to_number(std::string text) {
   //TODO check ujemne
  int result = 0;
  for (unsigned i = 0; i < text.size(); i++) {
    result += (text[i] - 48) * pow(10, text.size() - i - 1);
  }
  return result;
}

// TODO add bounds checking
 int ascii_to_number(char znak) { return znak - 48; }

//! parser

parser::parser(std::string text) {
  // rezerwujemy 512 * 512 for some performance bedzie troche mniej alokacji
  buffer_.reserve(512 * 512 * sizeof(char));
  current_state_ = new header();
  for (char i : text) {
    current_state_->read(i, this);
  }
}

std::vector<pixelRGB> parser::get() {
  // TODO check what when too many or too little
  std::vector<pixelRGB> result;
  for (unsigned i = 0; i < buffer_.size(); i += 3) {
    char r = buffer_[i + 0];
    char g = buffer_[i + 1];
    char b = buffer_[i + 2];
    result.push_back(pixelRGB(r, g, b));
  }
  return result;
}

void parser::change_state(state *new_state) {
  current_state_ = new_state;
}
parser::~parser() { delete current_state_; }

//! state
state::state() {}
// state::state(char) {}
void state::read(char , parser *) {
  ERR("WTF");
  exit(123);
}

//! comment
void comment::read(char znak, parser *machine) {
  DEBC(znak, "comment");
  if (znak == '\n' || znak == '\0') {
    machine->change_state(new whitespace());
    delete this;
  }
}

//! whitespace
void whitespace::read(char znak, parser *machine) {
  if (is_number(znak)) {
    machine->change_state(new number(znak));
    delete this;
  } else if (is_comment(znak)) {
    machine->change_state(new comment());
    delete this;
  }
}

//! number
number::number(char znak) : state() {
  DEBC(znak, "number");
  buff_ = znak;
}

void number::read(char znak, parser *machine) {
  if (is_number(znak)) {
    buff_ += znak;
  } else {
    if (to_number(buff_) < 256 && to_number(buff_) >= 0) {
      DEBC(to_number(buff_), "wartosc liczbowa");
      machine->buffer_.push_back(to_number(buff_));
      buff_ = "";
    } else {
      std::cout << buff_ << "==" << to_number(buff_) << std::endl;
      ERR("bad value");
    }
    if (is_comment(znak)) {
      machine->change_state(new comment());
      delete this;
    }
    else if (is_whitespace(znak)) {
      machine->change_state(new whitespace());
      delete this;
    }
  }
}

//! header
void header::read(char znak, parser *machine) {
  if (znak == '#') {
    machine->change_state(new header_comment());
    delete this;
  } else if (format_.size() < 2) {
    machine->change_state(new header_format());
    delete this;
  } else {
    machine->change_state(new header_dimentions());
    delete this;
  }
}

//! header comment
void header_comment::read(char znak, parser* machine) {
  if (znak == '\n') {
    machine->change_state(new header());
    delete this;
  }
}

//! header format
void header_format::read(char znak, parser* machine) {
  if (format_.size() == 1 && ascii_to_number(znak) < 6) {
    format_ += znak;
    is_binary_ = ascii_to_number(znak) > 3;
    machine->change_state(new header_dimentions());
    delete this;
  }
}

//! header dimentions
void header_dimentions::read(char znak,parser* machine) {
  if (dimentions_.size() < 4 && is_number(znak)) {
    buffer_ += znak;
  } else if (dimentions_.size() < 4) {
    dimentions_.push_back(to_number(buffer_));
    buffer_ = "";
  } else {
    machine->change_state(new number(znak));
    delete this;
  }
}
