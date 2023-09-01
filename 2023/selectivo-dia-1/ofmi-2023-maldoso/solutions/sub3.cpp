#include "maldoso.h"

void maldoso(int n) {
  int A[n];

  // Descubrir primeros dos
  // Iniciamos con [x, y]
  long a = pregunta(0, 1);  // [x + y, x - y]
  long b = pregunta(0, 1);  // [2x, 2y]
  A[1] = b / 2;             // = y
  A[0] = a + b / 2;         // (x - y) + y = x

  long ultimoValor = b;
  for (int i = 2; i < n; ++i) {
    // Antes de la pregunta tenemos [ultimo, nuevo]
    long c = pregunta(i - 1, i);  // [ultimo + nuevo, ultimo - nuevo]
    A[i] = -c + ultimoValor;
    ultimoValor = c;
  }

  // n + 1 pregunta
  pregunta(0, 1);
  respuesta(n, A);
}
