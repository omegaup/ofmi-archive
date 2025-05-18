// Sub4: Optimizacion de la subtarea 3, podemos determinar cual es la casa en la
// que vamos tomando el mayor entre el par de casas anteriores en O(n^2).

#include <iostream>
#include <vector>

int n;
std::vector<std::pair<int, int>> casas;
std::vector<std::vector<int>> memo;

int Busqueda(int prev_x, int prev_y) {
  int actual = std::max(prev_x, prev_y);

  if (actual == n) return 0;
  if (memo[prev_x][prev_y] > -1) return memo[prev_x][prev_y];

  int x = prev_x ? casas[prev_x - 1].first : 0;
  int y = prev_y ? casas[prev_y - 1].second : 0;

  return memo[prev_x][prev_y] = std::min(
             Busqueda(actual + 1, prev_y) + std::abs(x - casas[actual].first),
             Busqueda(prev_x, actual + 1) + std::abs(y - casas[actual].second));
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n;

  memo = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));

  casas = std::vector<std::pair<int, int>>(n);
  for (auto& [x, y] : casas) std::cin >> x >> y;
  std::cout << Busqueda(0, 0) << '\n';
}
