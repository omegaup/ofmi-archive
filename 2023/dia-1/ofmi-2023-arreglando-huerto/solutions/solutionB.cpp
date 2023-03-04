#include "arreglos.h"

void pasa(int indice, int cantidad, int direccion, int A[]) {
  if (cantidad == 0) {
    return;
  }
  A[indice] -= cantidad;
  A[indice + direccion] += cantidad;
  mueve(indice, cantidad, direccion);
}

void arreglaImpl(int n, int A[], int B[], int i, int carry) {
  if (i >= n) return;
  int diff = A[i] - B[i] - carry;
  if (diff > 0) {
    pasa(i, diff, 1, A);
    arreglaImpl(n, A, B, i + 1, 0);
  } else {
    arreglaImpl(n, A, B, i + 1, -diff);
  }
  pasa(i, carry, -1, A);
}

bool arregla(int n, int A[], int B[]) {
  int sumA = 0, sumB = 0;
  for (int i = 0; i < n; i++) {
    sumA += A[i];
    sumB += B[i];
  }
  if (sumA != sumB) return false;
  arreglaImpl(n, A, B, 0, 0);
  return true;
}
