#include "matrizsumasemipositiva.h"

int sumaFila[100];

void matrizSumaSemipositiva(int N, int M, int matriz[][100]) {
  // Calculamos las sumas
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      sumaFila[i] += matriz[i][j];
    }
  }
  // Reportamos la salida
  for (int i = 0; i < N; ++i) {
    if (sumaFila[i] < 0) {
      cambiaFila(i);
    }
  }
}
