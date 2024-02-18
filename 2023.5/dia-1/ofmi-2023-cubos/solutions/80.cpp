#include "cubos.h"

/**
    Puedo llenar dos caras a la vez si hago diagonales
*/

void cubo(int N) {
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      ponerBloque(x, y, y);
      ponerBloque(0, x, y);
    }
  }
}
