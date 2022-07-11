#include "matrizsumasemipositiva.h"

int sumaFila[100];
int cambiosFila[100];
int sumaColumna[100];
int cambiosColumna[100];

void cambiaFilaImpl(int N, int M, int matriz[][100], int fila) {
  cambiosFila[fila]++;
  sumaFila[fila] *= -1;
  for (int j = 0; j < M; ++j) {
    sumaColumna[j] -= 2 * matriz[fila][j];
    matriz[fila][j] *= -1;
  }
}

void cambiaColumnaImpl(int N, int M, int matriz[][100], int columna) {
  cambiosColumna[columna]++;
  sumaColumna[columna] *= -1;
  for (int i = 0; i < N; ++i) {
    sumaFila[i] -= 2 * matriz[i][columna];
    matriz[i][columna] *= -1;
  }
}

void matrizSumaSemipositiva(int N, int M, int matriz[][100]) {
  // Calculamos las sumas
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      sumaFila[i] += matriz[i][j];
      sumaColumna[j] += matriz[i][j];
    }
  }
  bool finished = false;
  while (!finished) {
    finished = true;
    // Encontramos una fila o columna cuya suma sea negativa
    for (int i = 0; i < N; ++i) {
      if (sumaFila[i] < 0) {
        cambiaFilaImpl(N, M, matriz, i);
        finished = false;
      }
    }
    for (int j = 0; j < M; ++j) {
      if (sumaColumna[j] < 0) {
        cambiaColumnaImpl(N, M, matriz, j);
        finished = false;
      }
    }
  }
  // Reportamos la salida
  for (int i = 0; i < N; ++i) {
    if (cambiosFila[i] & 1) {
      cambiaFila(i);
    }
  }
  for (int j = 0; j < M; ++j) {
    if (cambiosColumna[j] & 1) {
      cambiaColumna(j);
    }
  }
}
