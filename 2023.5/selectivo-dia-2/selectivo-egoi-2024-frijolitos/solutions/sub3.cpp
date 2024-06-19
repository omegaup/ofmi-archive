#include "frijolitos.h"

void frijolitos(long long N) {
  while (N) {
    const auto C = (N & 1) ? 1 : N >> 1;
    N -= C + tomar(C);
  }
}
