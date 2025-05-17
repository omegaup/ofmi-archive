// Greedy incorrecto: Tomar los eventos mas cortos (donde `e - s` sea menor) y,
// en caso de que haya empates, elegir los eventos con mayor valor.
// Hay que mantener los eventos ordenados para checar traslapes.

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Evento {
  bool operator<(const Evento& otro) const { return s < otro.s; }
  int Duracion() const { return e - s; }

  int s, e, v;
};

bool ComparaPorDuracion(const Evento& lhs, const Evento& rhs) {
  if (lhs.Duracion() == rhs.Duracion()) return lhs.v > rhs.v;
  return lhs.Duracion() < rhs.Duracion();
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<Evento> eventos(n);
  for (auto& [s, e, v] : eventos) std::cin >> s >> e >> v;
  std::sort(eventos.begin(), eventos.end(), ComparaPorDuracion);

  int max_valor = eventos[0].v;
  std::set<Evento> eventos_ordenados{eventos[0]};

  for (auto& [s, e, v] : eventos) {
    auto it = eventos_ordenados.lower_bound(Evento{e});
    if (it-- == eventos_ordenados.begin() || it->e <= s) {
      eventos_ordenados.insert(Evento{s, e, v});
      max_valor += v;
    }
  }
  std::cout << max_valor << '\n';
}
