// Esta solución parcial solo checa cuántas cobayas llegan a la lechuga y eso
// imprime
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

typedef std::pair<int, int> pii;
const int MAXN = 1002;

int n, m;
int tablero[MAXN][MAXN];
int tiempo[MAXN][MAXN];

void bfs(int x, int y) {
  std::queue<pii> q;
  q.push({x, y});
  for (int t = 0; !q.empty(); t++) {
    for (int idx = q.size(); idx > 0; idx--) {
      pii p = q.front();
      q.pop();
      if (tiempo[p.first][p.second] != -1) {
        continue;
      }
      tiempo[p.first][p.second] = t;
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
  }
}

int main() {
  std::cin >> n >> m;
  int x = -1, y = -1;
  int S = -1;
  int totalCobayas = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] > 1) {
        x = i;
        y = j;
        S = tablero[i][j];
      } else if (tablero[i][j] == 1) {
        totalCobayas++;
      }

      tiempo[i][j] = -1;
    }
  }

  bfs(x, y);

  std::vector<int> arr;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tablero[i][j] == 1 && tiempo[i][j] != -1) {
        arr.push_back(tiempo[i][j]);
      }
    }
  }

  std::sort(arr.begin(), arr.end());

  int t = 0;
  int i = 0;  // Indice del siguiente en comer (o bien, los que están comiendo)
  while (S > 0 && i < arr.size()) {
    S -= (arr[i] - t - 1) * i;
    t = arr[i];      // Avanzo hasta el tiempo t para empezar a comer
    int faltan = i;  // Los que faltan por comer en el tiempo t
    while (i < arr.size() && arr[i] == t && S > 0) {
      i++;
      S--;
    }
    S -= faltan;  // Los que no comieron en el tiempo t
  }

  std::cout << totalCobayas - i << std::endl;
  return 0;
}
