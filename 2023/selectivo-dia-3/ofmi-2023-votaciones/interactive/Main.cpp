#include <iostream>
#include <vector>

#include "votaciones.h"

const int MAXN = 1e6;
int ans_contestant[MAXN];
bool respuesta_llamada = false;
void resultados(int n, int R[]) {
  if (respuesta_llamada) {
    std::cerr << "Llamaste a respuesta mas de una vez" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  respuesta_llamada = true;
  for (int i = 0; i < n; ++i) {
    ans_contestant[i] = R[i];
  }
}

int N;
std::vector<bool> base;
std::vector<bool> nextState;
void generateNextState(int pot2) {
  int prev = (N + (pot2 % N)) % N;
  for (int i = 0; i < nextState.size(); ++i, prev = (prev + 1) % N) {
    nextState[i] = (base[i] ^ base[prev]);
  }
}

int ans_oficial[MAXN];
void votacionOficial(int n, int m, int A[]) {
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

  for (int i = 0; i < N; ++i) {
    ans_oficial[i] = (base[i] ? 1 : 0);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n y m
  int n, m;
  std::cin >> n >> m;
  // Leemos el arreglo A
  int A[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  // Llamamos a la función de la participante
  votacion(n, m, A);
  // Llamamos a la función oficial
  votacionOficial(n, m, A);

  if (!respuesta_llamada) {
    std::cerr << "No llamaste a respuesta" << std::endl;
    std::cout << 0 << std::endl;
    return 0;
  }

  bool same_answer = true;
  for (int i = 0; i < n; ++i) {
    if (ans_contestant[i] != ans_oficial[i]) {
      same_answer = false;
    }
  }
  // Comparamos las respuestas
  std::cout << (same_answer ? 1 : 0) << std::endl;

  return 0;
}
