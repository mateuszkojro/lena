#ifndef HELPERS_H
#define HELPERS_H

#include <math.h>
#include <string>

// klasa zostala utworozna tylko i wylacznie dla porzadku przechowujemy w niej jedynie pure czesto uzywane funkcjie w calym projekcie

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