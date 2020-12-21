#include <fstream>
#include <iostream>
#include <math.h>
#include <string>
#include <unordered_map>

#include "debug.h"
#include "obraz.h"
#include "ppm.h"

/* *
 *
 * You can inherit from unordered has map for better
 * code
 * unordered_map przyjmuje func haszujaca mozna dac swoja for better code
 * moze byc temlpatte dal typu w kptorym przechpowywac wartosci kolorow
 * */

// _____________ PARSER __________

// TODO We are leaking every new in every @read()
// TODO: while parsing if there is no whitespace after last symbol we will not
// parse it correctly
// because of the fact that if converts dopiero after
int main(int argc, char *argv[]) {
  TIME_START(all);
  try {
  obraz *o;
  if (argc < 2) {
    o = new ppm("../files/big_lena_full.ppm");
  } else {
    o = new ppm(argv[1]);
  }
  TIME_STOP(all, "all");
  std::cout << "there is: " << o->count_colors() << " colors" << std::endl;
  delete o;
  }
  catch(std::string & e) {
    std::cout << e;
  }
}
