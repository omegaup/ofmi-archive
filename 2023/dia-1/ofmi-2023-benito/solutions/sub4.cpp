#include <iostream>

const int maxn = 1000;

int n;
int matrix[maxn][maxn];

int distancia(int x, int y, int n) {
  // Regresa la distancia al extremo mas cercano
  return std::min(std::min(x + 1, y + 1), std::min(n - x, n - y));
}

int main() {
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> matrix[i][j];
    }
  }

  // Checamos si es espiral adentro hacia afuera
  int respuestaEsperada = (n + 1) / 2;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (matrix[i][j] != respuestaEsperada - distancia(i, j, n) + 1) {
        // No es una espiral adentro hacia afuera
        std::cout << "-1\n";
        return 0;
      }
    }
  }

  // Si es espiral adentro hacia afuera
  std::cout << (n + 1) / 2 << "\n";
  return 0;
}
