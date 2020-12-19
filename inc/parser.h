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

class state;
class number;
class comment;
class whitespace;
class parser;

//! HELPERS
inline bool is_number(char znak);
inline bool is_comment(char znak);
inline bool is_whitespace(char znak);
inline int to_number(std::string text);
inline int ascii_to_number(char znak);

//! STATES
class parser {
public:
  parser(std::string);
  std::vector<pixelRGB> get();
  inline void change_state(state *);
  std::vector<char> buffer_;
  ~parser();

protected:
  state *current_state_;
};

class state {
public:
  state();
  // state(char znak);
  virtual void read(char, parser *);
  virtual ~state() {}
};

class header : public state {
public:
  header() {}
  virtual void read(char, parser *);

protected:
  std::string format_;
  bool is_binary_;
  std::vector<unsigned> dimentions_;
};

class header_format : public header {
public:
  header_format() : header() { format_ += "P"; }
  void read(char, parser *);
};

class header_dimentions : public header {
public:
  header_dimentions() : header() {}
  void read(char, parser *);

protected:
  std::string buffer_;
};

class header_comment : public header {
public:
  header_comment() : header() {}
  void read(char, parser *);
};

class number : public state {
public:
  number(char);
  void read(char znak, parser *);

private:
//FIXME change this name na cos sensownego
  std::string buff_;
};

class comment : public state {
public:
  comment() : state() {}
  void read(char znak, parser *);
};

class whitespace : public state {
public:
  whitespace() : state() {}
  void read(char znak, parser *);
};

#endif