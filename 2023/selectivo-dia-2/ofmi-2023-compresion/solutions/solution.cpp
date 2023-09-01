#include <algorithm>
#include <iostream>

#include "compresion.h"

int compresion(int n, int m, int A[]) {
  std::sort(A, A + n);

  int distinct = 1;
  int i = 0;
  int j = 0;
  int best = n;
  int bestA = -1, bestB = -1;
  for (i = 0; i < n; i++) {
    if (j < i) {
      distinct = 1;
      j = i;
    }
    while (j < n - 1 && (distinct < m || A[j + 1] == A[j])) {
      if (A[j] < A[j + 1]) {
        distinct++;
      }
      j++;
    }
    int cambiados = n - (j - i + 1);
    if (cambiados < best) {
      best = cambiados;
      bestA = A[i];
      bestB = A[j];
    }
    if (i < n - 1 && A[i] < A[i + 1]) {
      distinct--;
    }
  }

  if (bestA != -1 && bestB != -1) {
    aplasta(bestA, bestB);
  }

  return best;
}
