#include <queue>
#include <tuple>

#include "viajecobayas.h"

bool vis[200][200];

// Asumir que ni buni ni facia están en un -1
typedef std::pair<int, int> pii;
int viajeCobayas(int N, int M, int matriz[][200], int r1, int c1, int r2,
                 int c2) {
  std::queue<pii> q;
  int t = 0;
  q.push({r1, c1});
  while (!q.empty()) {
    for (int i = q.size(); i > 0; --i) {
      int r, c;
      std::tie(r, c) = q.front();
      q.pop();
      if (r == r2 && c == c2) {
        return t;
      }
      if (r < 0 || c < 0 || r >= N || c >= M) {
        continue;
      } else if (matriz[r][c] == -1 || vis[r][c]) {
        continue;
      }
      vis[r][c] = true;
      q.push({r + 1, c});
      q.push({r - 1, c});
      q.push({r, c + 1});
      q.push({r, c - 1});
    }
    t++;
  }
  return -1;
}
