#include "maldoso.h"

void maldoso(int n) {
  int A[n];
  A[0] = pregunta(1, 0);
  for (int i = 1; i < n; ++i) {
    A[i] = pregunta(i - 1, i);
  }
  respuesta(n, A);
}
