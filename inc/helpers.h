#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <string>

//! HELPERS
inline bool is_digit(char znak);
inline bool is_comment(char znak);
inline bool is_whitespace(char znak);
inline int to_number(std::string text);
inline int ascii_to_number(char znak);

inline bool is_digit(char znak) { return (znak >= 48 && znak <= 57); }
inline bool is_comment(char znak) { return (znak == '#'); }
inline bool is_whitespace(char znak) {
  return (znak == '\t' || znak == ' ' || znak == '\n');
}

// TODO add bounds checking
inline int to_number(std::string text) {
  // TODO check ujemne
  int result = 0;
  for (unsigned i = 0; i < text.size(); i++) {
    result += (text[i] - 48) * pow(10, text.size() - i - 1);
  }
  return result;
}

// TODO add bounds checking
inline int ascii_to_number(char znak) { return znak - 48; }

#endif