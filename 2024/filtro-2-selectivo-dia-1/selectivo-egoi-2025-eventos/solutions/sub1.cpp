// Sub1: Busqueda recursiva sin acotar ni memorizar O(n^2 * 2^n).

#include <algorithm>
#include <iostream>
#include <vector>

struct Evento {
  bool Intersecta(const Evento& otro) { return otro.s < e && s < otro.e; }

  int s, e, v;
};

int max_valor = 0, n;
std::vector<Evento> eventos;

void Busqueda(int actual, std::vector<Evento> tomados) {
  if (actual == n) {
    bool hay_intersecciones = false;
    int valor = 0;

    for (int i = 0; i < tomados.size(); ++i) {
      for (int j = i + 1; j < tomados.size(); ++j) {
        hay_intersecciones |= tomados[i].Intersecta(tomados[j]);
        if (hay_intersecciones) break;
      }

      if (hay_intersecciones) break;
      valor += tomados[i].v;
    }

    if (!hay_intersecciones) max_valor = std::max(max_valor, valor);
    return;
  }

  Busqueda(actual + 1, tomados);
  tomados.push_back(eventos[actual]);
  Busqueda(actual + 1, tomados);
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n;

  eventos = std::vector<Evento>(n);
  for (auto& [s, e, v] : eventos) std::cin >> s >> e >> v;

  Busqueda(0, {});
  std::cout << max_valor << '\n';
}
