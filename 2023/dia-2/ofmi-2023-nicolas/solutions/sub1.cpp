#include "nicolas.h"

const int MAX = 1e3;

void nicolas() {
  // Intentamos adivinar la velocidad intentando pegarle
  // a la cola.
  // Iniciamos la primera foto en el segundo 1
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
  return reporta(X, 1);
}
