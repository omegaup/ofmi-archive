#include <iostream>

#include "subrangosBonitos.h"

int main() {
  // Lectura
  long long A, B;
  std::cin >> A >> B;

  std::cout << "El entero A es " << A << std::endl;
  std::cout << "El entero B es " << B << std::endl;

  std::cout << "Mandando a llamar tu función subRangosBonitos()" << std::endl;

  int resultado = subrangosBonitos(A, B);

  std::cout << "Resultado:  " << resultado << std::endl;

  return 0;
}
