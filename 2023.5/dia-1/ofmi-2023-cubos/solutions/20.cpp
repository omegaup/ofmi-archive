#include "cubos.h"

/**
    Llenamos todo el cubo
*/

void cubo(int N) {
  for (int x = 0; x < N; ++x) {
    for (int y = 0; y < N; ++y) {
      for (int z = 0; z < N; ++z) {
        ponerBloque(x, y, z);
      }
    }
  }
}
