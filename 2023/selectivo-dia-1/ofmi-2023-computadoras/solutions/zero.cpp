#include <algorithm>
#include <vector>

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

// Así al chilazo
void computadoras(int n, int p, int m, int P[], int M[]) {
  ordenaComputadoras(n, P, M);
  presenta(0);
  int currP = 0;
  int currM = 0;
  for (int i = 0; i < n; ++i) {
    if (currP < P[i] && currM < M[i]) {
      presenta(indices[i] + 1);
      currP = P[i];
      currM = M[i];
    }
  }
}
