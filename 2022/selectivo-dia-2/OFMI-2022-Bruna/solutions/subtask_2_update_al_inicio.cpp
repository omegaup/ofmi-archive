#include <iostream>
#include <vector>

#include "bruna.h"

int ganancias[100000 + 1];
std::vector<int> adyacencias[100000 + 1];

void update(int nodo, long long x) {
  ganancias[nodo] += x;
  int nx = x / 2ll;
  if (nx) {
    for (int i = 0; i < adyacencias[nodo].size(); i++) {
      update(adyacencias[nodo][i], nx);
    }
  }
}

void familiaBruna(int N, int mama[]) {
  for (int i = 0; i < N; i++) {
    if (mama[i] != -1) {
      adyacencias[mama[i]].push_back(i + 1);
    }
  }
}

bool actualizado = false;
void depositarDinero(int idx, int X) {
  if (actualizado) {
    return;
  }
  actualizado = true;
  update(idx, X);
}

long long int checarCuenta(int idx) { return ganancias[idx]; }
