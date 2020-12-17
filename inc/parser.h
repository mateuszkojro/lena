#ifndef PARSER_H
#define PARSER_H
#include <math.h>
#include <stdlib.h>
#include <string>
#include <vector>

#include "debug.h"
#include "pixel.h"
#include "pixelRGB.h"

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
inline int to_number(char znak);

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
  state(char znak);
  virtual void read(char, parser *);
  virtual ~state() {}
};

class header : public state {
public:
  header(char znak){}
  virtual void read(char, parser *);

protected:
  std::string format_;
  bool is_binary_;
  std::vector<unsigned> dimentions_;
};

class header_format : public header {
public:
  header_format(char znak) : header(znak) {
    format_ += "P";
    DEBC(znak, "header format");
  }
  void read(char, parser *);
};

class header_dimentions : public header {
public:
  header_dimentions(char znak) : header(znak) {
    DEBC(znak, "header dimentions");
  }
  void read(char, parser *);

protected:
  std::string buffer_;
};

class header_comment : public header {
public:
  header_comment(char znak) : header(znak) { DEBC(znak, "header comment"); }
  void read(char, parser *);

protected:
  std::string buffer_;
};

class number : public state {
public:
  number(char znak);
  void read(char znak, parser *);
  // virtual ~number() {}

private:
  std::string buff_;
};

class comment : public state {
public:
  comment(char znak) : state() { DEBC(znak, "comment"); }
  void read(char znak, parser *);
};

class whitespace : public state {
public:
  whitespace(char znak) : state() {}
  void read(char znak, parser *);
};

#endif