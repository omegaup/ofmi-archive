#include <iostream>

#include "maldoso.h"

void maldoso(int n) {
  // Crea un arreglo de n elementos
  int A[n];
  // Vamos a ir descifrando el arreglo de dos en dos
  for (int i = 0; i < n - 1; i += 2) {
    // Preguntamos por el valor de A[i] y A[i + 1]
    // Después de preguntar, tendremos:
    // A' = [..., A[i] + A[i+1], A[i] - A[i+1], ...]
    long a = pregunta(i, i + 1);  // a = A[i] - A[i+1]
    // Preguntamos por los dos elementos de nuevo
    // A' = [..., 2 * A[i], 2 * A[i+1], ...]
    long b = pregunta(
        i, i + 1);  // b = (A[i] + A[i+1]) - (A[i] - A[i-1]) = 2 * A[i+1]
    // Ahora podemos obtener A[i] y A[i+1]
    A[i + 1] = b / 2;     // pues b = 2 * A[i+1]
    A[i] = a + A[i + 1];  // pues a = A[i] - A[i+1]
  }
  if (n & 1) {
    // Si n es impar, nos falta descifrar el último elemento (A[n-1])
    // Por el momento, tenemos entonces: A = [..., (2 * A[n-3]), (2 * A[n-2]),
    // A[n-1]] Preguntamos por A[n-2] y A[n-1]
    long c = pregunta(n - 2, n - 1);
    A[n - 1] = 2 * A[n - 2] - c;  // pues c = (2 * A[n-2]) - A[n-1]
  }
  // Llamamos a la función respuesta
  respuesta(n, A);
}
