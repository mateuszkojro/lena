// #include "parser.h"

//  bool is_digit(char znak);
//  bool is_comment(char znak);
//  bool is_whitespace(char znak);
//  int to_number(std::string text);
//  int ascii_to_number(char znak);

// bool is_digit(char znak) { return (znak >= 48 && znak <= 57); }
// bool is_comment(char znak) { return (znak == '#'); }
// bool is_whitespace(char znak) {
//   return (znak == '\t' || znak == ' ' || znak == '\n');
// }

// // TODO add bounds checking
// int to_number(std::string text) {
//   // TODO check ujemne
//   int result = 0;
//   for (unsigned i = 0; i < text.size(); i++) {
//     result += (text[i] - 48) * pow(10, text.size() - i - 1);
//   }
//   return result;
// }

// // TODO add bounds checking
// int ascii_to_number(char znak) { return znak - 48; }

// //! parser
// // parser::parser(std::string text) {
// //   // rezerwujemy 512 * 512 for some performance - bedzie troche mniej alokacji
// //   buffer_.reserve(512 * 512 * sizeof(char));
// //   current_state_ = new header();
// //   for (char i : text) {
// //     current_state_->read(i, this);
// //   }
// // }
