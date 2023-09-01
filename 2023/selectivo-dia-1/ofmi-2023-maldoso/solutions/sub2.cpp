#include "maldoso.h"

void maldoso(int n) {
  int A[n];
  // [x, y, z]
  long a = pregunta(0, 1);  // [x + y, x - y]
  long b = pregunta(0, 1);  // [2x, 2y]
  A[1] = b / 2;             // = y
  A[0] = a + b / 2;         // (x - y) + y = x
  if (n >= 3) {
    A[2] = -pregunta(1, 2) + b;  // [2x, 2y+z, 2y-z]
  }
  respuesta(n, A);
}
