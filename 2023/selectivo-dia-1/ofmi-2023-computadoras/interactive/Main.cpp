#include <algorithm>
#include <iostream>
#include <vector>

#include "computadoras.h"

const int MAXN = 5002;
int n;
int p, m;
int P[MAXN], M[MAXN];

std::vector<int> presentadas;
bool presentadoCorrectamente = true;
int ultimaPresentada = -1;  // índice de la última computadora presentada
bool presenta(int identificador) {
  if (ultimaPresentada == -1) {
    if (identificador == 0) {
      ultimaPresentada = 0;
      presentadas.push_back(0);
      return true;
    } else {
      std::cerr << "La primera computadora debe ser la ofmi" << std::endl;
      presentadoCorrectamente = false;
      return false;
    }
  }
  if (identificador < 0 || identificador > n) {
    std::cerr << "El índice de la computadora debe estar entre 0 y n"
              << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  int pUltima = ultimaPresentada == 0 ? p : P[ultimaPresentada - 1];
  int mUltima = ultimaPresentada == 0 ? m : M[ultimaPresentada - 1];
  if (P[identificador - 1] <= pUltima) {
    std::cerr << "La computadora " << identificador
              << " no es más potente que la última presentada "
              << ultimaPresentada << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  if (M[identificador - 1] <= mUltima) {
    std::cerr << "La computadora " << identificador
              << " no tiene más memoria que la última presentada "
              << ultimaPresentada << std::endl;
    presentadoCorrectamente = false;
    return false;
  }
  presentadas.push_back(identificador);
  ultimaPresentada = identificador;
  return true;
}

// Ordena las computadoras 1 a la n
// en indices[i] queda el indice original de la computadora i
void ordenaComputadoras(int n, int P[], int M[]) {
  int indices[n];
  for (int i = 0; i < n; ++i) {
    indices[i] = i;
  }
  std::sort(indices, indices + n, [&](int i, int j) {
    return P[i] < P[j] || (P[i] == P[j] && M[i] < M[j]);
  });
  int P_ordenado[n], M_ordenado[n];
  for (int i = 0; i < n; ++i) {
    P_ordenado[i] = P[indices[i]];
    M_ordenado[i] = M[indices[i]];
  }
  for (int i = 0; i < n; ++i) {
    P[i] = P_ordenado[i];
    M[i] = M_ordenado[i];
  }
}

// Esta función devuelve la máxima cantidad de computadoras que puedes presentar
int computadorasMaximas(int n, int p, int m, int P[], int M[]) {
  ordenaComputadoras(n, P, M);
  // Do DP
  int dp[n];
  dp[n - 1] = 1;
  for (int i = n - 2; i >= 0; --i) {
    dp[i] = 1;
    for (int j = i + 1; j < n; ++j) {
      if (P[i] < P[j] && M[i] < M[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (p >= P[i] || m >= M[i]) {
      continue;
    }
    ans = std::max(ans, dp[i] + 1);
  }
  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n
  std::cin >> n;
  // Leemos p y m
  std::cin >> p >> m;
  // Leemos las otras n computadoras
  for (int i = 0; i < n; ++i) {
    std::cin >> P[i] >> M[i];
  }

  // Llamamos a la solución de la participante
  computadoras(n, p, m, P, M);

  // Llamamos a la solución oficial
  int computadorasOficial = computadorasMaximas(n, p, m, P, M);

  if (presentadoCorrectamente && presentadas.size() == computadorasOficial) {
    std::cout << 1 << std::endl;
  } else {
    std::cout << 0 << std::endl;
  }
  return 0;
}
