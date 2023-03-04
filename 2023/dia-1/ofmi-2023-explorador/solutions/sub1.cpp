#include <iostream>
#include <vector>

int main() {
  // Lectura de datos
  int N, M;
  std::cin >> N >> M;

  // Primer subcaso : Una linea
  if (N == 1) {
    // Leer linea
    std::vector<int> linea(M);
    for (int i = 0; i < M; ++i) {
      std::cin >> linea[i];
    }

    // Cambiar todo a la derecha
    int costo = 0;
    for (int i = 0; i < M - 1; ++i) {
      costo += (linea[i] != 1);
      linea[i] = 1;
    }

    // Imprimir respuesta
    std::cout << costo << "\n";
    for (int i = 0; i < M; ++i) {
      std::cout << linea[i] << " ";
    }
    std::cout << "\n";
  } else {
    // No lo resolvemos
    std::cout << "-1\n";
  }
}
