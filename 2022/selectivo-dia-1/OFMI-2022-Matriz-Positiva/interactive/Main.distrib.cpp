#include <iostream>
#include <queue>
#include <vector>

#include "matrizsumasemipositiva.h"

int N, M;
int matriz[100][100];

void imprimeMatriz() {
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> matriz[i][j];
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void cambiaFila(int fila) {
  std::cout << "Llamaste a cambiaFila(" << fila << ")" << std::endl;
  for (int j = 0; j < M; ++j) {
    matriz[fila][j] *= -1;
  }
  std::cout << "Ahora el estado actual de la matriz es:" << std::endl;
  imprimeMatriz();
}

void cambiaColumna(int columna) {
  std::cout << "Llamaste a cambiaColumna(" << columna << ")" << std::endl;
  for (int i = 0; i < N; ++i) {
    matriz[i][columna] *= -1;
  }
  std::cout << "Ahora el estado actual de la matriz es:" << std::endl;
  imprimeMatriz();
}

int main() {
  std::cin >> N >> M;
  std::cout << "El entero N es " << N << std::endl;
  std::cout << "El entero M es " << M << std::endl;
  std::cout << "La matriz es " << std::endl;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> matriz[i][j];
      std::cout << matriz[i][j] << " ";
    }
    std::cout << std::endl;
  }
  matrizSumaSemipositiva(N, M, matriz);
  std::cout << "El estado final de la matriz es:" << std::endl;
  imprimeMatriz();
  return 0;
}
