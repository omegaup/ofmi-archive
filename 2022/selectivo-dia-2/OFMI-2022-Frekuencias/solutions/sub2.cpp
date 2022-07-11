#include <algorithm>

#include "frekuencias.h"

int frekuencia(int N, char S[]) {
  int respuesta = 0;
  int suma = 0;
  // A suma, B resta
  for (int i = 0; i < N; i++) {
    suma += S[i] == 'a' ? 1 : -1;
    if (suma < 0)
      suma = 0;
    else
      respuesta = std::max(suma, respuesta);
  }
  suma = 0;
  // A suma, B resta
  for (int i = 0; i < N; i++) {
    suma += S[i] == 'b' ? 1 : -1;
    if (suma < 0)
      suma = 0;
    else
      respuesta = std::max(suma, respuesta);
  }
  return respuesta;
}
