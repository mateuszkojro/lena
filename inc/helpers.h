#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <string>

//! HELPERS
class helpers {
public:
  static inline bool is_digit(char znak);
  static inline bool is_comment(char znak);
  static inline bool is_whitespace(char znak);
  static inline int to_number(std::string text);
  static inline int ascii_to_number(char znak);
};


#endif