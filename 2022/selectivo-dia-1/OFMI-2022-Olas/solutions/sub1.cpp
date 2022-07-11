#include "waves.h"

const int MaxN = 101;
int N;
int arr[MaxN];

int exhaustiva(int pos, int cambiosValidos) {
  if (pos == N + 1) {
    return 0;
  }
  int minCantidad =
      (arr[pos - 1] > arr[pos]) + exhaustiva(pos + 1, cambiosValidos);
  if (cambiosValidos) {
    int val = arr[pos];
    arr[pos] = arr[pos - 1];
    int minNuevo = exhaustiva(pos + 1, cambiosValidos - 1);
    if (minNuevo < minCantidad) {
      minCantidad = minNuevo;
    }
    arr[pos] = val;
  }
  return minCantidad;
}

int waves(int n, int k, int A[]) {
  N = n;
  for (int i = 1; i <= n; ++i) arr[i] = A[i - 1];
  arr[0] = -1e9;
  return exhaustiva(1, k);
}
