/*
Sub 1. Dado que n <= 3, podemos asegurarnos de que se puede ordenar el arreglo
        sin terminarnos las paletas.
*/
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << 0 << std::endl;
  } else if (n == 2) {
    int a, b;
    std::cin >> a >> b;
    if (a == 1 && b == 2) {
      std::cout << 0 << std::endl;
    } else {
      std::cout << 1 << std::endl;
    }
  } else {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == 1 && b == 2 && c == 3) {
      std::cout << 0 << std::endl;
    } else if (a == 1 && b == 3 && c == 2) {
      std::cout << 1 << std::endl;
    } else if (a == 2 && b == 1 && c == 3) {
      std::cout << 1 << std::endl;
    } else if (a == 2 && b == 3 && c == 1) {
      std::cout << 2 << std::endl;
    } else if (a == 3 && b == 1 && c == 2) {
      std::cout << 2 << std::endl;
    } else if (a == 3 && b == 2 && c == 1) {
      std::cout << 3 << std::endl;
    }
  }
  return 0;
}