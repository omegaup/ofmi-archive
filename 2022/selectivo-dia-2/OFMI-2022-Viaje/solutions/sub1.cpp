#include <stdlib.h>

#include "viajecobayas.h"

int viajeCobayas(int N, int M, int matriz[][200], int r1, int c1, int r2,
                 int c2) {
  return abs(r1 - r2) + abs(c1 - c2);
}
