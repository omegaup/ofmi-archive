#include "frijolitos.h"

// Main
//	long long tomar(long long cantidad)

void frijolitos(long long n) {
  while (n > 0) {
    n -= 1 + tomar(1);
  }
}
