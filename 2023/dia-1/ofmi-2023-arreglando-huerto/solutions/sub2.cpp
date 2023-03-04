#include "arreglos.h"

// Llamamos mueve2 para mantener actualizado también nuestro arreglo A
void mueve2(int i, int d, int dir, int A[]) {
  mueve(i, d, dir);
  A[i] -= d;
  A[i + dir] += d;
}

bool arregla(int n, int A[], int B[]) {
  int sumA = 0, sumB = 0;
  for (int i = 0; i < n; i++) {
    sumA += A[i];
    sumB += B[i];
  }
  // Nos aseguramos que existe solución
  if (sumA != sumB) return false;
  // Movemos todos los elementos a la izquierda
  for (int i = n - 1; i > 0; i--) {
    mueve2(i, A[i], -1, A);
  }
  // Aplicamos el mismo algoritmo que la subtarea 1.
  for (int i = 0; i < n - 1; i++) {
    mueve2(i, A[i] - B[i], 1, A);
  }
  return true;
}
