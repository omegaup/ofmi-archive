#include <iostream>
#include <queue>
#include <vector>

#include "matrizsumasemipositiva.h"

int N, M;
int matriz[100][100];

bool isSub4() { return N == 100 && M == 100; }

int cambieFila[100], cambieColumna[100];
bool invalidOp{};

void cambiaFila(int fila) {
  if (fila < 0 || fila >= N) {
    invalidOp = true;
    return;
  }

  cambieFila[fila]++;
}

void cambiaColumna(int columna) {
  if (columna < 0 || columna >= M) {
    invalidOp = true;
    return;
  }

  cambieColumna[columna]++;
}

bool checaMatriz() {
  if (invalidOp) return false;

  bool twice{};

  // Checar que la suma de las filas sea positiva
  for (int i = 0; i < N; ++i) {
    int sumaFila = 0;
    for (int j = 0; j < M; ++j) {
      if ((cambieFila[i] + cambieColumna[j]) % 2 == 0) {
        sumaFila += matriz[i][j];
      } else {
        sumaFila -= matriz[i][j];
      }
    }
    twice |= cambieFila[i] > 1;
    if (sumaFila < 0) {
      return false;
    }
  }

  // Checar que la suma de las columnas sea positiva
  for (int j = 0; j < M; ++j) {
    int sumaColumna = 0;
    for (int i = 0; i < N; ++i) {
      if ((cambieFila[i] + cambieColumna[j]) % 2 == 0) {
        sumaColumna += matriz[i][j];
      } else {
        sumaColumna -= matriz[i][j];
      }
    }
    twice |= cambieColumna[j] > 1;
    if (sumaColumna < 0) {
      return false;
    }
  }

  return !isSub4() || !twice;
}

int main() {
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> matriz[i][j];
    }
  }
  matrizSumaSemipositiva(N, M, matriz);
  if (checaMatriz()) {
    std::cout << "1.00" << std::endl;
  } else {
    std::cout << "0.00" << std::endl;
  }
  return 0;
}
