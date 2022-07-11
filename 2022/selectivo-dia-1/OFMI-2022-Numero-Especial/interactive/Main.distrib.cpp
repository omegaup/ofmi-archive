#include <iostream>

#include "numeroespecial.h"

int main() {
  long long n, m, k;
  std::cin >> n >> m >> k;
  std::cout << "El entero n es " << n << std::endl;
  std::cout << "El entero m es " << m << std::endl;
  std::cout << "El entero k es " << k << std::endl;
  std::cout << "Mandando a llamar tu función numeroEspecial()" << std::endl;
  std::cout << "Tu función regresó: " << numeroEspecial(n, m, k) << std::endl;
  return 0;
}
