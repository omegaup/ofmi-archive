#include "frijolitos.h"

void frijolitos(long long N) {
  while (N > 0) {
    long long c = 0;
    if (N & 1) {
      c = 1;
    } else if (N % 4 == 0 && N != 4) {
      c = 1;
    } else {
      c = N >> 1;
    }
    N -= c;
    N -= tomar(c);
  }
}