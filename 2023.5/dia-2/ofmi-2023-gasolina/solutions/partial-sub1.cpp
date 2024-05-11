#include <algorithm>

#include "energia.h"

void avanzaMaximo(int n, int L) {
  // Solución para n = 2.

  mueve(0, L / 2);
  mueve(1, L / 2);
  pasaEnergia(0, 1, L / 2);
  mueve(1, L);
}
