#include <algorithm>
#include <iostream>

#include "compresion.h"

/*
Si todos los A's son distintos, debemos cambiar n - m elementos.
Entonces tomemos [b_0, b_1, b_2, ... b_{m-1}] con B siendo A ordenado
*/
int compresion(int n, int m, int A[]) {
  std::sort(A, A + n);
  aplasta(A[0], A[m - 1]);
  return n - m;
}
