#include <iostream>
#include <vector>

#include "bruna.h"

std::vector<int> ganancias;

void familiaBruna(int N, int mama[]) {
  ganancias.resize(N + 1);
  fill(ganancias.begin(), ganancias.end(), 0);
}

void depositarDinero(int idx, int X) { ++ganancias[idx]; }

long long int checarCuenta(int idx) { return ganancias[idx]; }
