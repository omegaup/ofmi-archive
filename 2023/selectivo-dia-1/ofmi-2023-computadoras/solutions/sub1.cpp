#include <algorithm>

#include "computadoras.h"

// Obtener cada permutación de N
void computadoras(int n, int p, int m, int P[], int M[]) {
  int perm[n];
  for (int i = 0; i < n; ++i) {
    perm[i] = i;
  }
  int ans = 1;
  int bestPerm[n] = {0};
  do {
    // contamos cuantos podemos presentar
    int presentados = 1;
    int currP = p;
    int currM = m;
    for (int i = 0; i < n; ++i) {
      if (currP >= P[perm[i]] || currM >= M[perm[i]]) {
        break;
      }
      presentados++;
      currP = P[perm[i]];
      currM = M[perm[i]];
    }
    if (presentados > ans) {
      ans = presentados;
      for (int i = 0; i < n; ++i) {
        bestPerm[i] = perm[i];
      }
    }
  } while (std::next_permutation(perm, perm + n));

  presenta(0);

  for (int i = 0; i < ans - 1; ++i) {
    presenta(bestPerm[i] + 1);
  }
}
