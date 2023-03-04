#include "arreglos.h"

// Llamamos mueve2 para mantener actualizado también nuestro arreglo A
void mueve2(int i, int d, int dir, int A[]) {
  mueve(i, d, dir);
  A[i] -= d;
  A[i + dir] += d;
}

bool arregla(int n, int A[], int B[]) {
  for (int i = 0; i < n - 1; i++) {
    mueve2(i, A[i] - B[i], 1, A);
  }
  return true;
}
