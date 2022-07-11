#include <iostream>
#include <vector>

#include "bruna.h"

constexpr int MAX_N = 1e6 + 2;
constexpr int MAX_PROFUNDIDAD = 30;  // ⌈log_2(10 ^ 9)⌉

struct Nodo {
  std::vector<long long> ganancias_hijos;
  int madre;
} arbol[MAX_N];

long long obtenGanancias(int nodo, int ancestro) {
  if (nodo == -1 || ancestro >= MAX_PROFUNDIDAD) return 0;
  return arbol[nodo].ganancias_hijos[ancestro] +
         obtenGanancias(arbol[nodo].madre, ancestro + 1);
}

void familiaBruna(int N, int mama[]) {
  for (int i = 1; i <= N; i++) {
    arbol[i].madre = mama[i - 1];
    arbol[i].ganancias_hijos.assign(MAX_PROFUNDIDAD + 2, 0LL);
  }
}

void depositarDinero(int idx, int X) {
  for (int j = 0; X; j++) {
    arbol[idx].ganancias_hijos[j] += X;
    X /= 2;
  }
}

long long int checarCuenta(int idx) { return obtenGanancias(idx, 0); }
