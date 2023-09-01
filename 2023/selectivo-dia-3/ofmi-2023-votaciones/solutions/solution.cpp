#include <iostream>
#include <vector>

#include "votaciones.h"

int N;
std::vector<bool> base;
std::vector<bool> nextState;
void generateNextState(int pot2) {
  int prev = (N + (pot2 % N)) % N;
  for (int i = 0; i < nextState.size(); ++i, prev = (prev + 1) % N) {
    nextState[i] = (base[i] ^ base[prev]);
  }
}

void votacion(int n, int m, int A[]) {
  int M = m;
  N = n;
  base.resize(N);
  nextState.resize(N);
  for (int i = 0; i < N; ++i) {
    base[i] = (A[i] == 1);
  }

  int pot2 = 1;
  while (M > 0) {
    if (M & pot2) {
      generateNextState(pot2);
      M -= pot2;
      std::swap(base, nextState);
    }
    pot2 *= 2;
  }

  int R[n];
  for (int i = 0; i < N; ++i) {
    R[i] = (base[i] ? 1 : 0);
  }
  resultados(n, R);
}
