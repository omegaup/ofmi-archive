#include "ruleta.h"

int indice1;
int factor = 1;
bool ret = true;

bool checa(int val, int x) {
  if (val * factor < indice1 * factor) return ret;
  if (val >= x)
    return true;
  else
    return false;
}

int encuentra(int x, int n) {
  indice1 = pregunta(0);

  if (indice1 == x) return 0;

  // Preparacion para la binaria
  int fin = n - 1;
  int ini = 1;
  int mid;

  if (indice1 > x) {
    // Estructura >>><<<=>>
    ret = false;
    factor = -1;
  }

  // Si no: Estructura <<<=>>><<<
  int v;
  while (ini != fin) {
    mid = (ini + fin) / 2;

    int v = pregunta(mid);

    if (v == x) return mid;

    if (checa(v, x))
      fin = mid;
    else
      ini = mid + 1;
  }

  if (pregunta(fin) == x)
    return fin;
  else
    return -1;
}
