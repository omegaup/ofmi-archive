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

  int ans;
  if (m == 1) {
    // Si m es 1, la respuesta es el mayor elemento
    ans = A[max_id];
  } else if (m == 2) {
    // Si m es 2, la respuesta es el menor elemento de las esquinas
    ans = std::min(A[0], A[n - 1]);
  } else {
    // Si m es 3 o más, la respuesta es el menor elemento
    ans = A[min_id];
  }

  return ans;
}
