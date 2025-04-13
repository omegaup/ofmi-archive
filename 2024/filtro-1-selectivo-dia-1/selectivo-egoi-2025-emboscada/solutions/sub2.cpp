// Sub2: Cuando k < n, todos los hangares estan disponibles entonces k + 1.
// Para k == n la respuesta es el hangar con menor tiempo de espera.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  if (k < n) {
    std::cout << 0 << ' ' << k + 1 << '\n';
    return 0;
  }

  int min_t, index = 0;
  std::cin >> min_t;

  for (int i = 1; i < n; ++i) {
    int t;
    std::cin >> t;
    if (t < min_t) {
      min_t = t;
      index = i;
    }
  }
  std::cout << min_t << ' ' << index + 1 << '\n';
}
