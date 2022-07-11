#include <iostream>
#include <vector>

#include "bruna.h"

// Esta solucion no sirve dado que floor(x) + floor(x/2) + ... != floor(x + x/2
// + ...)

constexpr int MAX_N = 1e6 + 2;
constexpr int MAX_PROFUNDIDAD = 30;  // ⌈log_2(10 ^ 9)⌉

struct Nodo {
  long long ganancias;
  int madre;
} arbol[MAX_N];

long long obtenGanancias(int nodo, int ancestro) {
  if (nodo == -1 || ancestro >= MAX_PROFUNDIDAD) return 0;
  // 1 << ancenstro simplemente es otra forma de expresar pow(2, ancestro)
  return arbol[nodo].ganancias / (1 << ancestro) +
         obtenGanancias(arbol[nodo].madre, ancestro + 1);
}

void familiaBruna(int N, int mama[]) {
  for (int i = 1; i <= N; i++) {
    arbol[i].madre = mama[i - 1];
  }
}

void depositarDinero(int idx, int X) { arbol[idx].ganancias += X; }

long long int checarCuenta(int idx) { return obtenGanancias(idx, 0); }
