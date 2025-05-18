// Sub3: Fijando una posicion, por ejemplo la `0`, podemos buscar cual es el
// shift del arreglo con una busqueda binaria. Despues de encontrar el shift,
// podemos volver a hacer busqueda binaria "rotando" el arreglo.

#include "ruleta.h"

int encuentra(int x, int n) {
  int A0 = pregunta(0);
  if (A0 == x) return 0;

  int l = 0, r = n;
  while (l + 1 < r) {
    int m = (l + r) / 2;

    int Am = pregunta(m);
    if (Am == x) return m;

    if (A0 < Am)
      l = m;
    else
      r = m;
  }

  int shift = l + 1;

  l = 0, r = n;
  while (l < r) {
    int m = (l + r) / 2;

    int Am = pregunta((m + shift) % n);
    if (Am == x) return (m + shift) % n;

    if (Am < x)
      l = m + 1;
    else
      r = m;
  }
  return -1;
}
