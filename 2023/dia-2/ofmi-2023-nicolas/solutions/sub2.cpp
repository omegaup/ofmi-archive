#include "nicolas.h"

const int MAX = 1e3;

void nicolas() {
  // Asumimos que la velocidad es 1
  // Ahora intentamos adivinar la longitud
  // intentando darle a la cabeza
  // Iniciamos la primera foto en el segundo 1
  int tiempo = 0;
  int L;
  for (L = 1; L < MAX; ++L) {
    tiempo++;
    if (!foto(tiempo + L - 1)) {
      L--;
      break;
    }
  }
  return reporta(1, L);
}
