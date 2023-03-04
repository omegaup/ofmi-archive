#include "nicolas.h"

const int MAX = 1e3;

void nicolas() {
  // Primero intentamos adivinar la velocidad intentando pegarle
  // a la cola. Iniciamos la primera foto en el segundo 1
  int tiempo = 0;
  int X;
  for (X = 1; X < MAX; ++X) {
    // Si tuviera velocidad X, la cola estaría en la posición X*tiempo
    tiempo++;  // Hacemos pasar un segundo
    if (foto(X * tiempo)) {
      // Si la foto dio positivo, entonces la cola está en la posición X
      break;
    }
  }
  // Ahora intentamos adivinar la longitud con busqueda binaria
  // intentando darle a la cabeza
  int l = 1, r = MAX;
  while (l < r) {
    int m = (l + r + 1) / 2;
    tiempo++;  // Hacemos pasar un segundo
    if (foto(X * tiempo + m - 1)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  return reporta(X, l);
}
