#include <cstring>
#include <iostream>

#include "waves.h"

const int INF = 1e9;

int N, K;
int a[101];

const int MAX = 101;
int memo[MAX][MAX][MAX];

int dp(int i, int l, int k) {
  if (k > K) return INF;
  if (i > N + 1) {
    return std::max(0, i - l - 1);
  }
  if (memo[i][l][k] != -1) {
    return memo[i][l][k];
  }
  memo[i][l][k] = INF;
  memo[i][l][k] = std::min(memo[i][l][k], dp(i + 1, l, k));
  memo[i][l][k] =
      std::min(memo[i][l][k], dp(i + 1, i, k + i - l - 1) + (int)(a[l] > a[i]));
  return memo[i][l][k];
}

int waves(int n, int k, int A[]) {
  N = n;
  K = k;
  for (int i = 0; i < n; i++) {
    a[i + 1] = A[i];
  }
  memset(memo, -1, sizeof(memo));
  a[0] = -INF;
  a[n + 1] = INF;
  return dp(1, 0, 0);
}