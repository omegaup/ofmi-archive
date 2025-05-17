// Sub1: Busqueda recursiva acotando cuando la respuesta no mejora.

#include <iostream>
#include <vector>

constexpr int kMaxN = 1e4;
constexpr int kMaxX = 10;

int conteo[kMaxX], visitado[kMaxN];
int n, m, min_diferentes = kMaxX + 1;
std::vector<std::pair<int, int>> aristas[kMaxN];

int ContarDiferentes() {
  int diferentes = 0;
  for (int i = 0; i < kMaxX; ++i) diferentes += conteo[i] > 0;
  return diferentes;
}

void Busqueda(int u) {
  if (u == n - 1) {
    min_diferentes = std::min(ContarDiferentes(), min_diferentes);
    return;
  }

  // Detenemos la busqueda si el numero de valores diferentes es mayor a la
  // minima respuesta que hemos calculado hasta el momento.
  if (ContarDiferentes() >= min_diferentes) return;

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
