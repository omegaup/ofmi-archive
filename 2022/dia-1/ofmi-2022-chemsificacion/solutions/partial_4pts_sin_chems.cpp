#include <iostream>

int main() {
  // Cantidad de palabras
  int N;
  std::cin >> N;

  // Leer las N palabras
  std::string palabra;
  for (int i = 0; i < N; ++i) {
    std::cin >> palabra;
    // Imprimir sin chemsificar
    std::cout << palabra << (i + 1 < N ? ' ' : '\n');
  }
}
