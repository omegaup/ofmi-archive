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

  std::vector<std::pair<int, int>> bloques;
  int acumulado = 0, ant_x = cambios[0].first;

  for (auto [x, e] : cambios) {
    if (ant_x < x) bloques.push_back({acumulado, x - ant_x});
    acumulado += e;
    ant_x = x;
  }

  std::sort(bloques.begin(), bloques.end());
  for (int i = bloques.size() - 2; i >= 0; --i)
    bloques[i].second += bloques[i + 1].second;

  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;

    auto it =
        std::upper_bound(bloques.begin(), bloques.end(), std::make_pair(x, 0));

    if (it != bloques.end())
      std::cout << it->second << "\n";
    else
      std::cout << "0\n";
  }
}
