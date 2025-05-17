// Sub3: Solo hay dos valores, usamos una BFS donde solo las aristas con valor
// 1 o 2 son permitidas, si `1` y `n` estan conectados, la respuesta es "1".
// En caso contrario, checamos si `1` y `n` estan conectados en absoluto, si
// lo estan la respuesta es "2", sino la respuesta es "-1".

#include <iostream>
#include <queue>
#include <vector>

constexpr int kMaxN = 1e4;

std::vector<std::pair<int, int>> aristas[kMaxN];

bool EstanConectados(int inicio, int fin, const std::vector<int>& permitir) {
  std::queue<int> q;
  std::vector<bool> visitado(kMaxN);

  q.push(inicio);
  visitado[inicio] = true;

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    if (u == fin) return true;

    for (auto [v, x] : aristas[u]) {
      if (visitado[v] || !permitir[x]) continue;
      visitado[v] = true;
      q.push(v);
    }
  }
  return false;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;

  while (m--) {
    int u, v, x;
    std::cin >> u >> v >> x;
    aristas[--u].push_back({--v, --x});
    aristas[v].push_back({u, x});
  }

  if (EstanConectados(0, n - 1, {1, 0}) || EstanConectados(0, n - 1, {0, 1})) {
    std::cout << "1\n";
    return 0;
  }
  std::cout << (EstanConectados(0, n - 1, {1, 1}) ? "2\n" : "-1\n");
}
