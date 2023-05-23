#include "votaciones.h"

void votacion(int n, int m, int A[]) {
  int ans[n];
  for (int i = 0; i < n; ++i) {
    ans[i] = 0;
  }
  resultados(n, ans);
}
