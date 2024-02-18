#include <algorithm>

#include "energia.h"

void avanzaMaximo(int n, int L) {
  // En cada iteración avanzaremos todos los corredores que aún tengan
  // energia 1 kilómetro. Luego la mitad de los corredores pasarán el
  // litro de energia que les queda a la otra mitad. Repetimos
  // el proceso hasta que quede un solo corredor con energia.
  while (n > 1) {
    for (int i = 0; i < n; i++) {
      mueve(i, 1);
    }

    n /= 2;
    for (int i = 0; i < n; i++) {
      pasaEnergia(i + n, i, 1);
    }
  }
  mueve(0, 2);
}
