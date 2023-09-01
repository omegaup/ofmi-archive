#include <iostream>

#include "michmo.h"

int N, M, P, A, B;

void devolver(int p, int a, int b) {
  std::clog << "Regresaste el tiro con los parametros: \n";
  std::clog << " - Posicion (" << N << ", " << p << ")\n";
  std::clog << " - Pendiente " << A << "/" << B << "\n";
}

void terminar() { std::clog << "Reportaste que el tiro fue invalido\n"; }

int main() {
  // Leemos el caso
  std::cin >> N >> M;
  std::cin >> P >> A >> B;

  // Llamamos a la función de la participante
  michmo(N, M, P, A, B);
  std::cout << 1 << std::endl;
  return 0;
}
