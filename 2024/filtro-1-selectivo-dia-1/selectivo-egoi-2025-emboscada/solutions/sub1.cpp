// Sub1: Simular el tiempo restante en cada hangar cada minuto.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> t(n);
  for (int& ti : t) std::cin >> ti;

  int minuto_actual = 0;
  std::vector<int> espera(n, 1);

  while (true) {
    for (int i = 0; i < n; ++i) {
      if (--espera[i]) continue;

      if (!k--) {
        std::cout << minuto_actual << ' ' << i + 1 << '\n';
        return 0;
      }
      espera[i] = t[i];
    }
    ++minuto_actual;
  }
}
