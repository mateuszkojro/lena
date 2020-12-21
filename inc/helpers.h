#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <string>

//! HELPERS
class helpers {
public:
  static  bool is_digit(char znak);
  static  bool is_comment(char znak);
  static  bool is_whitespace(char znak);
  static  int to_number(std::string text);
  static  int ascii_to_number(char znak);
};


#endif