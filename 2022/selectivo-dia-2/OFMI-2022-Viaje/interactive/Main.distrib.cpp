#include <iostream>
#include <queue>
#include <vector>

#include "viajecobayas.h"

int matriz[200][200];

int main() {
  int N, M;
  std::cin >> N >> M;
  std::cout << "El entero N es " << N << std::endl;
  std::cout << "El entero M es " << M << std::endl;
  std::cout << "La matriz es:" << std::endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> matriz[i][j];
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
  int r1, c1, r2, c2;
  std::cin >> r1 >> c1;
  std::cin >> r2 >> c2;
  std::cout << "La posición de Boni es (" << r1 << "," << c1 << ")"
            << std::endl;
  std::cout << "La posición Facia es (" << r2 << "," << c2 << ")" << std::endl;
  int obtained = viajeCobayas(N, M, matriz, r1, c1, r2, c2);

  std::cout << "Tu progama responde: " << obtained << "\n";
  return 0;
}
