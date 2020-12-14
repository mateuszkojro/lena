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

// HELPERS
bool is_number(char znak);
bool is_comment(char znak);
bool is_whitespace(char znak);
int to_number(std::string text);
int to_number(char znak);

// STATES

class state {
public:
  state();
  state(char znak);
  virtual state *read(char znak, std::vector<char> &out);
  virtual ~state() {}
};

class header : public state {
public:
  header(char znak) { DEBC(znak, "header"); }
  virtual state *read(char znak, std::vector<char> &out);

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
  state *read(char, std::vector<char> &);
};

class header_dimentions : public header {
public:
  header_dimentions(char znak) : header(znak) {
    DEBC(znak, "header dimentions");
  }
  state *read(char, std::vector<char> &);

protected:
  std::string buffer_;
};

class header_comment : public header {
public:
  header_comment(char znak) : header(znak) { DEBC(znak, "header comment"); }
  state *read(char, std::vector<char> &);

protected:
  std::string buffer_;
};

class number : public state {
public:
  number(char znak);
  state *read(char znak, std::vector<char> &out);
  virtual ~number() {}

private:
  std::string buff_;
};

class comment : public state {
public:
  comment(char znak) : state() { DEBC(znak, "comment"); }
  state *read(char znak, std::vector<char> &out);
};

class whitespace : public state {
public:
  whitespace(char znak) : state() { /* DEBC(znak, "whitespace");*/
  }
  state *read(char znak, std::vector<char> &out);
};

// TODO: co z kopiowaniem, "=", delete itd
class parser {
public:
  parser(std::string);
  std::vector<pixelRGB> get();
  ~parser();

protected:
  state *current_state_;
  std::vector<char> buffer_;
};

#endif