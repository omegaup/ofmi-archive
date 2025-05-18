#include <iostream>

constexpr int kMaxN = 1e6;

int espia[kMaxN];
int etiqueta[kMaxN];
int profundidad[kMaxN];

void MarcarProfundidadCiclo(int u) {
  etiqueta[u] = 1;
  while (!etiqueta[espia[u]]) {
    etiqueta[espia[u]] = etiqueta[u] + 1;
    u = espia[u];
  }

  if (profundidad[espia[u]]) return;

  profundidad[u] = etiqueta[u] - etiqueta[espia[u]] + 1;
  while (!profundidad[espia[u]]) {
    profundidad[espia[u]] = profundidad[u];
    u = espia[u];
  }
}

int Profundidad(int u) {
  if (profundidad[u]) return profundidad[u];
  return profundidad[u] = Profundidad(espia[u]) + 1;
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int u;
    std::cin >> u;
    espia[i] = u - 1;
  }

  int maximo_camino = 0;
  for (int i = 0; i < n; ++i) {
    if (etiqueta[i]) continue;

    MarcarProfundidadCiclo(i);
    maximo_camino = std::max(maximo_camino, Profundidad(i));
  }
  std::cout << maximo_camino << '\n';
}
