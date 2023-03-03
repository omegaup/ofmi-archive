#include <vector>

#include "arreglos.h"

using ll = long long;

// Rutina que reporta el movimiento al evaluador y modifica los valores
// que tenemos guardados en el arreglo.
void mueve2(int i, int d, int dir, int A[]) {
  mueve(i, d, dir);
  A[i] -= d;
  A[i + dir] += d;
}

bool arregla(int n, int A[], int B[]) {
  // En cada iteración ya se habrá resuelto el prefijo [0, i).
  for (int i = 0; i < n; i++) {
    // Se calcula la mínima j >= i tal que el subarreglo [i, j] puede ser
    // arreglado usando solo operaciones en [i, j].
    int j = i;
    ll delta = 0;
    for (; j < n; j++) {
      delta += A[j] - B[j];
      if (delta >= 0) break;
    }

    // Si no encontramos tal j, no hay solución.
    if (j == n) {
      return false;
    }

    // Se pasa a la derecha lo que sobra para resolver [i, j].
    // Si no hay a dónde pasar lo que sobra, no hay solución.
    if (delta > 0) {
      if (j == n - 1) {
        return false;
      }
      mueve2(j, delta, 1, A);
    }

    // Se resuelve [i, j].
    for (; j > i; j--) {
      if (A[j] > B[j]) {
        mueve2(j, A[j] - B[j], -1, A);
      }
    }
  }

  return true;
}
