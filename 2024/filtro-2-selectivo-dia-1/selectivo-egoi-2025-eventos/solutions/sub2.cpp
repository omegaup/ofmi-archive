// Sub2: Como los valores de los eventos son iguales, podemos simplemente tomar
// la mayor cantidad de eventos que no se traslapen. Para esto, ordenamos los
// eventos por su tiempo de fin y los tomamos mientras el inicio del evento
// actual no ocurra antes del fin del evento anterior.
//
// Este codigo ademas sirve para probar que este greedy, usando como segunda
// prioridad los eventos con mayor valor, no es una solucion correcta.

#include <algorithm>
#include <iostream>
#include <vector>

struct Evento {
  bool operator<(const Evento& otro) const {
    if (e == otro.e) return v > otro.v;
    return e < otro.e;
  }

  int s, e, v;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<Evento> eventos(n);
  for (auto& [s, e, v] : eventos) std::cin >> s >> e >> v;
  std::sort(eventos.begin(), eventos.end());

  int final_actual = 0, max_valor = 0;
  for (auto& [s, e, v] : eventos) {
    if (s < final_actual) continue;
    final_actual = e;
    max_valor += v;
  }
  std::cout << max_valor << '\n';
}
