#include <iostream>

#include "aplusb.h"

int A, B;

int valorB() {
  std::cout << "Mandaste a llamar valorB(). Regresa: " << B << std::endl;
  return B;
}

int main() {
  int A, B;
  std::cin >> A >> B;
  std::cout << "Llamando a tu funcion suma(" << A << ")" << std::endl;
  int C = suma(A);
  std::cout << "Tu funcion suma(" << A << ") "
            << "(B=" << B << ") devolvio " << C << std::endl;
  if (C != A + B) {
    std::cout << "Respuesta incorrecta :(" << std::endl;
  } else {
    std::cout << "Respuesta correcta :)" << std::endl;
  }
  return 0;
}