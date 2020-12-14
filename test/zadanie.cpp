#include "ppm.h"
#include <iostream>

int main() {
  obraz *obraz1;
  obraz1 = new ppm("../test/test_files/lena_full.ppm");

  int kolor;

  kolor = liczkolory(*obraz1);

  std::cout << "Liczba unikalnych kolorow w obrazie ";
  std::cout << kolor;

  delete obraz1;

  return 0;
}