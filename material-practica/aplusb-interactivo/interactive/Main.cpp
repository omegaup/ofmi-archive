#include <iostream>

#include "aplusb.h"

int A, B;

int valorB() {
  return B;
}

int main() {
  std::cin >> A >> B;
  int C = suma(A);
  if (C != A + B) {
    std::cout << 0 << std::endl;
  } else {
    std::cout << 1 << std::endl;
  }
  return 0;
}