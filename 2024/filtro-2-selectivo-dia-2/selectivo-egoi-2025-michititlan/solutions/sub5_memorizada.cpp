// Esta es una version alterna de la solucion oficial, usa recursion memorizada
// y esperamos que por usar mal la memoria de MLE, pero esta bien si pasa igual.

#include <iostream>
#include <vector>

constexpr int kMaxX = 1000;

int n;
std::vector<std::pair<int, int>> casas;
std::vector<std::vector<std::vector<int>>> memo;

int Busqueda(int actual, int prev, int es_vertical) {
  if (actual == n) return 0;
  if (memo[es_vertical][actual][prev] > -1)
    return memo[es_vertical][actual][prev];

  int x = es_vertical ? prev : (actual ? casas[actual - 1].first : kMaxX);
  int y = es_vertical ? (actual ? casas[actual - 1].second : kMaxX) : prev;

  return memo[es_vertical][actual][prev] = std::min(
             Busqueda(actual + 1, y, 0) + std::abs(x - casas[actual].first),
             Busqueda(actual + 1, x, 1) + std::abs(y - casas[actual].second));
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n;

  memo = std::vector<std::vector<std::vector<int>>>(
      2, std::vector<std::vector<int>>(n, std::vector<int>(2 * kMaxX + 1, -1)));

  casas = std::vector<std::pair<int, int>>(n);
  for (auto& [x, y] : casas) {
    std::cin >> x >> y;
    x += kMaxX;
    y += kMaxX;
  }
  std::cout << Busqueda(0, kMaxX, 0) << '\n';
}
