// Sub2: Dado que nos aseguran que los elementos del arreglo estan en su
// posicion original, podemos hacer busqueda binaria normal.

#include "ruleta.h"

int encuentra(int x, int n) {
  int l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;

    int Am = pregunta(m);
    if (Am == x) return m;

    if (Am < x)
      l = m + 1;
    else
      r = m;
  }
  return -1;
}
