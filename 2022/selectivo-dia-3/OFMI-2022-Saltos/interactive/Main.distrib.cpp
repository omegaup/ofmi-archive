#include <iostream>

#include "cobayasaltarina.h"

int main() {
  int k, n;
  std::cin >> k >> n;
  std::cout << "El entero k es " << k << std::endl;
  std::cout << "El entero n es " << n << std::endl;
  int hoyos[n];

  std::cout << "Los " << n << " hoyos están en: ";
  for (int i = 0; i < n; ++i) {
    std::cin >> hoyos[i];
    std::cout << hoyos[i] << " ";
  }
  std::cout << std::endl;

  std::cout << "Tu función regresó: " << cobayaSaltarina(k, n, hoyos)
            << std::endl;

  return 0;
}
