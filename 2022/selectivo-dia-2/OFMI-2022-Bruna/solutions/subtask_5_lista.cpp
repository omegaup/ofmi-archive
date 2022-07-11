/*
Resultado Esperado 40 puntos:
- (10 puntos) $X = 1$
- (30 puntos) Es una linea, no un árbol.
*/

#include <iostream>
#include <vector>

#include "bruna.h"

long long ganancias[100000 + 1];
int adyacencias[100000 + 1];

void update(int nodo, long long x) {
  ganancias[nodo] += x;
  int nx = x / 2ll;
  if (nx) {
    update(adyacencias[nodo], nx);
  }
}

void familiaBruna(int N, int mama[]) {
  for (int i = 0; i < N; i++) {
    if (mama[i] != -1) {
      adyacencias[mama[i]] = i + 1;
    }
  }
}

void depositarDinero(int idx, int X) { update(idx, X); }

long long int checarCuenta(int idx) { return ganancias[idx]; }
