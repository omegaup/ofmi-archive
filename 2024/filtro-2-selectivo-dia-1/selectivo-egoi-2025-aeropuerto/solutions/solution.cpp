#include <iostream>
#include <queue>
#include <vector>

constexpr int kMaxN = 1e4;
constexpr int kMaxX = 10;

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

  int min_diferentes = kMaxX + 1;
  std::vector<int> permitir(kMaxX);

  for (permitir[0] = 0; permitir[0] < 2; ++permitir[0]) {
    for (permitir[1] = 0; permitir[1] < 2; ++permitir[1]) {
      for (permitir[2] = 0; permitir[2] < 2; ++permitir[2]) {
        for (permitir[3] = 0; permitir[3] < 2; ++permitir[3]) {
          for (permitir[4] = 0; permitir[4] < 2; ++permitir[4]) {
            for (permitir[5] = 0; permitir[5] < 2; ++permitir[5]) {
              for (permitir[6] = 0; permitir[6] < 2; ++permitir[6]) {
                for (permitir[7] = 0; permitir[7] < 2; ++permitir[7]) {
                  for (permitir[8] = 0; permitir[8] < 2; ++permitir[8]) {
                    for (permitir[9] = 0; permitir[9] < 2; ++permitir[9]) {
                      if (EstanConectados(0, n - 1, permitir)) {
                        int diferentes = 0;
                        for (int i = 0; i < kMaxX; ++i)
                          diferentes += permitir[i];
                        min_diferentes = std::min(diferentes, min_diferentes);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  std::cout << ((min_diferentes > kMaxX) ? -1 : min_diferentes) << '\n';
}
