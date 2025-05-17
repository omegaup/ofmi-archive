// Sub2: Dado que todos los nodos tienen dos aristas, el grafo que se forma son
// ciclos simples. Iniciando en el nodo `1`, podemos darle la vuelta al ciclo
// por ambos lados hasta llegar al nodo `n`. Si en algun momento regresamos
// al nodo `1`, no hay respuesta pues `1` y `n` no estan conectados.

#include <iostream>
#include <vector>

constexpr int kMaxN = 1e4;
constexpr int kMaxX = 10;

int conteo[kMaxX];
int n, m, min_diferentes = kMaxX + 1;
std::vector<std::pair<int, int>> aristas[kMaxN];

void Recorrer(int u, int p) {
  // Si regresamos al inicio y no es a primer llamada.
  if (!u && p) return;

  if (u == n - 1) {
    int diferentes = 0;
    for (int i = 0; i < kMaxX; ++i) diferentes += conteo[i] > 0;
    min_diferentes = std::min(diferentes, min_diferentes);
    return;
  }

  for (auto [v, x] : aristas[u]) {
    if (v == p) continue;
    ++conteo[x];
    Recorrer(v, u);
    --conteo[x];
  }
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

  Recorrer(0, 0);
  std::cout << ((min_diferentes > kMaxX) ? -1 : min_diferentes) << '\n';
}
