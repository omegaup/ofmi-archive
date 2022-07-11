#include "viajecobayas.h"

bool vis[200][200];

int min(int a, int b) {
  if (a == -1) return b;
  if (b == -1) return a;
  return a < b ? a : b;
}

int viajeCobayas(int N, int M, int matriz[][200], int r1, int c1, int r2,
                 int c2) {
  if (N > 5 || M > 5) {
    return -1;
  }
  if (r1 == r2 && c1 == c2) {
    return 0;
  }
  if (r1 < 0 || c1 < 0 || r1 >= N || c1 >= M) {
    return -1;
  }
  if (vis[r1][c1] || matriz[r1][c1] == -1) {
    return -1;
  }
  vis[r1][c1] = true;
  int menor = min(min(viajeCobayas(N, M, matriz, r1 + 1, c1, r2, c2),
                      viajeCobayas(N, M, matriz, r1 - 1, c1, r2, c2)),
                  min(viajeCobayas(N, M, matriz, r1, c1 + 1, r2, c2),
                      viajeCobayas(N, M, matriz, r1, c1 - 1, r2, c2)));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      if (matriz[i][j] == matriz[r1][c1]) {
        menor = min(menor, viajeCobayas(N, M, matriz, i, j, r2, c2));
      }
    }
  }
  vis[r1][c1] = false;
  return menor == -1 ? -1 : menor + 1;
}
