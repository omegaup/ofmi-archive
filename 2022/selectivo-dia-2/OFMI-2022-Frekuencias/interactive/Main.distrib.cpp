#include <iostream>

#include "frekuencias.h"

int main() {
  // Lectura
  int N;
  std::cin >> N;
  std::cout << "El entero N es " << N << std::endl;
  char C[N + 1];
  for (int i = 0; i < N; i++) {
    std::cin >> C[i];
  }
  C[N] = 0;
  std::cout << "La lista de colores C es " << C << std::endl;

  int reportedFrekuencia = frekuencia(N, C);
  std::cout << "Tu función regresó: " << reportedFrekuencia << std::endl;
  return 0;
}
