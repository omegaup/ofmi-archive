#include <algorithm>
#include <iostream>
#include <map>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::map<int, int> cubeta;
  while (n--) {
    int t;
    std::cin >> t;
    ++cubeta[t];
  }

  int tamano_anterior = -1;
  int matrioshkas_abiertas = 0;
  int matrioshkas_totales = 0;

  for (auto& [tamano_actual, repeticiones] : cubeta) {
    matrioshkas_totales +=
        (tamano_actual == tamano_anterior + 1)
            ? std::max(repeticiones - matrioshkas_abiertas, 0)
            : repeticiones;

    matrioshkas_abiertas = repeticiones;
    tamano_anterior = tamano_actual;
  }
  std::cout << matrioshkas_totales << '\n';
}
