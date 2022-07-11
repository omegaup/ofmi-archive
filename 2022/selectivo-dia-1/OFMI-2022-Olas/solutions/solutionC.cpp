#include <algorithm>

#include "waves.h"

bool vis[100][100][100];
int memo[100][100][100];
int N;

int wave(int i, int j, int A[]) {
  if (i == -1 || j == -1) {
    return 0;
  }
  return A[i] > A[j] ? 1 : 0;
}

int dp(int i, int ant, int k, int A[]) {
  if (i < 0) {
    return 0;
  }
  if (!vis[i][ant][k]) {
    vis[i][ant][k] = true;
    // No ocupes k en la posición i
    memo[i][ant][k] = dp(i - 1, i, k, A) + wave(i, ant, A);
    // Sí cambia la posición i
    if (k > 0)
      for (int j = 0; j < N; ++j) {
        memo[i][ant][k] =
            std::min(memo[i][ant][k], dp(i - 1, j, k - 1, A) + wave(j, ant, A));
      }
  }
  return memo[i][ant][k];
}

int waves(int n, int k, int A[]) {
  N = n;
  return dp(n - 1, -1, k, A);
}
