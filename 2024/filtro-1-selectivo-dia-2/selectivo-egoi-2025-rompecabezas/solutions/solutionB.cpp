#include <iostream>
#include <set>
#include <utility>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> conteo(std::min(n, q) + 1);
  std::set<std::pair<int, int>> rompecabezas;

  for (int i = 1; i <= std::min(n, q); i++) {
    rompecabezas.insert({0, i});
  }

  for (int i = 0; i < q; i++) {
    char tipo;
    int ri;
    std::cin >> tipo >> ri;
    if (tipo == '+') {
      if (ri > q) {
        continue;
      }
      int actual = conteo[ri];
      auto it = rompecabezas.lower_bound({actual, ri});
      rompecabezas.erase(it);

      conteo[ri]++;
      rompecabezas.insert({actual + 1, ri});
    } else {
      if (ri <= q) {
        int actual = conteo[ri];
        auto it = rompecabezas.lower_bound({actual, ri});
        rompecabezas.erase(it);

        conteo[ri]--;
        rompecabezas.insert({actual - 1, ri});
      }

      auto buscado = rompecabezas.begin();
      if (buscado->first > 0) {
        std::cout << -1 << '\n';
      } else {
        std::cout << buscado->second << '\n';
      }
    }
  }
}
