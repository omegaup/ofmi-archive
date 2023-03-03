// Esta solución parcial solo checa cuántas cobayas llegan a la lechuga y eso
// imprime
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> pii;
const int MAXN = 1001;

int n, m;
int tablero[MAXN][MAXN];
bool vis[MAXN][MAXN];

int main() {
  std::cin >> n >> m;
  int x = -1, y = -1;
  int S = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] > 1) {
        x = i;
        y = j;
        S = tablero[i][j];
      }
    }
  }

  int c = 0;
  std::queue<pii> q;
  q.push({x, y});
  while (!q.empty()) {
    pii p = q.front();
    q.pop();
    if (vis[p.first][p.second]) {
      continue;
    }
    vis[p.first][p.second] = true;
    if (p.first > 0 && tablero[p.first - 1][p.second] != -1) {
      q.push({p.first - 1, p.second});
    }
    if (p.first < n - 1 && tablero[p.first + 1][p.second] != -1) {
      q.push({p.first + 1, p.second});
    }
    if (p.second > 0 && tablero[p.first][p.second - 1] != -1) {
      q.push({p.first, p.second - 1});
    }
    if (p.second < m - 1 && tablero[p.first][p.second + 1] != -1) {
      q.push({p.first, p.second + 1});
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j] && tablero[i][j] == 1) {
        c++;
      }
    }
  }

  std::cout << std::min(S, c) << std::endl;
  return 0;
}