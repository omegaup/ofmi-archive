// Sub1: Preguntar por todas las posiciones una por una.

#include "ruleta.h"

int encuentra(int x, int n) {
  for (int i = 0; i < n; ++i)
    if (pregunta(i) == x) return i;
  return -1;
}
