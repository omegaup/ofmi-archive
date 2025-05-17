// Sub1: Busqueda recursiva sin acotar ni memorizar. Los grafos que se forman en
// la subtarea 2 son ciclos simples, por lo que es posible recorrerlos en un
// sentido o el opuesto, por lo que este codigo tambien pasa esa subtarea!

#include <iostream>
#include <vector>

constexpr int kMaxN = 1e4;
constexpr int kMaxX = 10;

int conteo[kMaxX], visitado[kMaxN];
int n, m, min_diferentes = kMaxX + 1;
std::vector<std::pair<int, int>> aristas[kMaxN];

void Busqueda(int u) {
  if (u == n - 1) {
    int diferentes = 0;
    for (int i = 0; i < kMaxX; ++i) diferentes += conteo[i] > 0;
    min_diferentes = std::min(diferentes, min_diferentes);
    return;
  }

  visitado[u] = 1;
  for (auto [v, x] : aristas[u]) {
    if (visitado[v]) continue;
    ++conteo[x];
    Busqueda(v);
    --conteo[x];
  }
  visitado[u] = 0;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n >> m;

  while (m--) {
    int u, v, x;
    std::cin >> u >> v >> x;
    aristas[--u].push_back({--v, --x});
    aristas[v].push_back({u, x});
  }

  Busqueda(0);
  std::cout << ((min_diferentes > kMaxX) ? -1 : min_diferentes) << '\n';
}
