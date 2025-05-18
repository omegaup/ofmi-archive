// Sub2: Busqueda recursiva sin acotar ni memorizar O(2^n).

#include <iostream>
#include <vector>

int n;
std::vector<std::pair<int, int>> casas;

int Busqueda(int actual, int x, int y) {
  if (actual == n) return 0;

  return std::min(Busqueda(actual + 1, casas[actual].first, y) +
                      std::abs(x - casas[actual].first),
                  Busqueda(actual + 1, x, casas[actual].second) +
                      std::abs(y - casas[actual].second));
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n;

  casas = std::vector<std::pair<int, int>>(n);
  for (auto& [x, y] : casas) std::cin >> x >> y;
  std::cout << Busqueda(0, 0, 0) << '\n';
}
