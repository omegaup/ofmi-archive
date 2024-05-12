#include <iostream>

#include "frijolitos.h"

typedef long long int lld;

lld optimo(lld x) {
  if (x > 8 && (x % 4) == 0) {
    return 1;
  }
  return x & 1 ? 1 : x / 2;
}

void frijolitos(lld n) {
  while (n > 0) {
    const lld cantidad = optimo(n);
    n -= cantidad;
    n -= tomar(cantidad);
  }
}
