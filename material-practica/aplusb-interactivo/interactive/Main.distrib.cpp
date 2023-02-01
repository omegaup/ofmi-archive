#include <iostream>

#include "aplusb.h"

int A, B;

int valorB() {
  std::cerr << "Mandaste a llamar valorB(). Regresa: " << B << std::endl;
  return B;
}

int main() {
  std::cin >> A >> B;
  std::cerr << "Llamando a tu funcion suma(" << A << ")" << std::endl;
  int C = suma(A);
  std::cerr << "Tu funcion suma(" << A << ") "
            << "(B=" << B << ") devolvio " << C << std::endl;
  if (C != A + B) {
    std::cerr << "Respuesta incorrecta :(" << std::endl;
    std::cout << 0 << std::endl;
  } else {
    std::cerr << "Respuesta correcta :)" << std::endl;
    std::cout << 1 << std::endl;
  }
  return 0;
}
