#include <iostream>

#include "minminmax.h"

int minMinMax(int n, int m, int A[]) {
  // Guardamos el indice del minimo y el maximo
  int min_id = 0;
  int max_id = 0;
  // Buscamos el minimo y el maximo
  for (int i = 0; i < n; ++i) {
    if (A[i] > A[max_id]) {
      max_id = i;
    }
    if (A[i] < A[min_id]) {
      min_id = i;
    }
  }

  return std::min(A[0], A[n - 1]);
}
