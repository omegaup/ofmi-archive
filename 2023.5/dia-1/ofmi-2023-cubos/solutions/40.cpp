#include "cubos.h"

/**
    Tapamos toda la caras completamente
*/

void cubo(int N) {
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      ponerBloque(x, y, 0);
      ponerBloque(0, x, y);
      ponerBloque(x, 0, y);
    }
  }
}
