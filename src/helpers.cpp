#include "helpers.h"

bool helpers::is_digit(char znak) { return (znak >= 48 && znak <= 57); }
bool helpers::is_comment(char znak) { return (znak == '#'); }
bool helpers::is_whitespace(char znak) {
  return (znak == '\t' || znak == ' ' || znak == '\n');
}

// TODO add bounds checking
int helpers::to_number(std::string text) {
  // TODO check ujemne
  int result = 0;
  for (unsigned i = 0; i < text.size(); i++) {
    result += (ascii_to_number(text[i])) * pow(10, text.size() - i - 1);
  }
  return result;
}

// TODO add bounds checking
int helpers::ascii_to_number(char znak) { return znak - 48; }
