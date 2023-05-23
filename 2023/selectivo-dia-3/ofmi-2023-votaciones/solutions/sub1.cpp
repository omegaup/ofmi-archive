#include <iostream>
#include <vector>

#include "votaciones.h"

void votacion(int n, int m, int A[]) {
  int prev[n];
  int curr[n];
  for (int i = 0; i < n; ++i) {
    curr[i] = A[i];
  }
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < n; ++i) {
      prev[i] = curr[i];
    }
    for (int i = 0; i < n; ++i) {
      int neighbor = (i + 1) % n;
      if (prev[neighbor] == 1) {
        curr[i] = prev[i] ^ 1;
      } else {
        curr[i] = prev[i];
      }
    }
  }
  resultados(n, curr);
}
