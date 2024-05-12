#include "frijolitos.h"

void frijolitos(long long N) {
  while (N) {
    N -= 1 + tomar(1);
  }
}
