#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<std::pair<int, int>> cambios(2 * k);
  for (int i = 0; i < k; ++i) {
    int l, r, e;
    std::cin >> l >> r >> e;
    cambios[2 * i] = {l, e};
    cambios[2 * i + 1] = {r + 1, -e};
  }

  std::sort(cambios.begin(), cambios.end());

  std::vector<int> cubeta(k + 1);
  int acumulado = 0, ant_x = cambios[0].first;

  for (auto [x, e] : cambios) {
    if (ant_x < x) cubeta[acumulado] += x - ant_x;
    acumulado += e;
    ant_x = x;
  }

  for (int i = k - 1; i; --i) cubeta[i] += cubeta[i + 1];

  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;
    if (x > k)
      std::cout << "0\n";
    else
      std::cout << cubeta[x] << "\n";
  }
}
