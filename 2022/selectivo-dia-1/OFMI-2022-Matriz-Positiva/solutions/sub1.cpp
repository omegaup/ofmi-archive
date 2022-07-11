#include "matrizsumasemipositiva.h"

int sumaColumna[100];

void matrizSumaSemipositiva(int N, int M, int matriz[][100]) {
  // Calculamos las sumas
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      sumaColumna[j] += matriz[i][j];
    }
  }
  // Reportamos la salida
  for (int j = 0; j < M; ++j) {
    if (sumaColumna[j] < 0) {
      cambiaColumna(j);
    }
  }
}
