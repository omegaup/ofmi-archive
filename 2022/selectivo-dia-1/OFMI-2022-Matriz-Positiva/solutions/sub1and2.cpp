#include "matrizsumasemipositiva.h"

bool possible(int N, int M, int matriz[][100], int mscFilas, int mscColumnas) {
  for (int i = 0; i < N; ++i) {
    int sumaFila = 0;
    for (int j = 0; j < M; ++j) {
      bool cambieCasilla = ((mscFilas & (1 << i)) > 0 ? 1 : 0) ^
                           ((mscColumnas & (1 << j)) > 0 ? 1 : 0);
      sumaFila += matriz[i][j] * (cambieCasilla ? -1 : 1);
    }
    if (sumaFila < 0) {
      return false;
    }
  }
  for (int j = 0; j < M; ++j) {
    int sumaColumna = 0;
    for (int i = 0; i < N; ++i) {
      bool cambieCasilla = ((mscFilas & (1 << i)) > 0 ? 1 : 0) ^
                           ((mscColumnas & (1 << j)) > 0 ? 1 : 0);
      sumaColumna += matriz[i][j] * (cambieCasilla ? -1 : 1);
    }
    if (sumaColumna < 0) {
      return false;
    }
  }
  return true;
}

void matrizSumaSemipositiva(int N, int M, int matriz[][100]) {
  if (N == 1) {
    // Reportamos la salida
    for (int j = 0; j < M; ++j) {
      if (matriz[0][j] < 0) {
        cambiaColumna(j);
      }
    }
    return;
  }
  for (int mscFilas = 0; mscFilas < (1 << N); mscFilas++) {
    for (int mscColumnas = 0; mscColumnas < (1 << M); mscColumnas++) {
      if (possible(N, M, matriz, mscFilas, mscColumnas)) {
        // Reporta salida y termina
        for (int i = 0; i < N; ++i) {
          if (mscFilas & (1 << i)) {
            cambiaFila(i);
          }
        }
        for (int j = 0; j < M; ++j) {
          if (mscColumnas & (1 << j)) {
            cambiaColumna(j);
          }
        }
        return;
      }
    }
  }
}
