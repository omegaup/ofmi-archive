#include <algorithm>

#include "computadoras.h"

const int MAXN = 5002;
// Ordena las computadoras 1 a la n
// en indices[i] queda el indice original de la computadora i
int indices[MAXN];
void ordenaComputadoras(int n, int P[], int M[]) {
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

void computadoras(int n, int p, int m, int P[], int M[]) {
  ordenaComputadoras(n, P, M);
  // Do DP
  int dp[n];
  dp[n] = 1;
  for (int i = n - 1; i >= 0; --i) {
    dp[i] = 1;
    for (int j = i + 1; j <= n; ++j) {
      if (P[i] < P[j] && M[i] < M[j]) {
        dp[i] = std::max(dp[i], dp[j] + 1);
      }
    }
  }

  // Buscar la respuesta
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    if (p >= P[i] || m >= M[i]) {
      continue;
    }
    ans = std::max(ans, dp[i] + 1);
  }

  // Reconstruir dp
  int curr = -1;
  int currDP = ans;
  int pCurr = p;
  int mCurr = m;
  presenta(0);
  for (int i = 0; i < n; ++i) {
    if (currDP == dp[i] + 1 && P[i] > pCurr && M[i] > mCurr) {
      curr = i;
      currDP = dp[i];
      pCurr = P[i];
      mCurr = M[i];
      presenta(indices[curr] + 1);
    }
  }
}
