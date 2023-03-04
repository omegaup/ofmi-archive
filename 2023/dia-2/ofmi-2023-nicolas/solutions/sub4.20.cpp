#include "nicolas.h"

int segundo = 0;

// usamos una funcion que lleva el tiempo
// para que nosotros no tengamos que llevarlo
bool intenta(int v, int l) {
  segundo++;
  // std::cout << "intenta " << v << " " << l << std::endl;
  return foto((v * segundo) + l);
}

void nicolas() {
  int v, l = 0;

  // primero buscamos la velocidad
  // intentando con todos los valores desde 1 hasta 10000
  for (int i = 1; i < 10001; i++) {
    if (intenta(i, 0)) {
      v = i;
      break;
    }
  }

  // busqueda binaria para la longitud
  int a = 0;
  int b = 10000;
  while (a < b) {
    int m = (a + b) / 2;
    // si no salio en la foto, la longitud es menor
    if (intenta(v, m)) {
      a = m + 1;
    } else {
      b = m;
    }
  }

  l = a;

  reporta(v, l);
}
