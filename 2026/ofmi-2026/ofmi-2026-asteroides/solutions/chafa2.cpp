/*  Probar simulacion a fuerza bruta */
/*  48 ptrs / 52 pts con sync */
#include <algorithm>
#include <iostream>
#include <vector>

bool simular(long long inicial, std::vector<long long> &asteroides) {
  long long actual = inicial;

  for (auto &asteroide : asteroides) {
    if (actual < asteroide) return false;

    actual += asteroide;
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n;
  long long l = 0, r = 0;
  std::cin >> n;

  std::vector<long long> asteroides(n);

  for (int i = 0; i < n; i++) {
    std::cin >> asteroides[i];
    r = std::max(r, asteroides[i]);
  }

  std::sort(asteroides.begin(), asteroides.end());

  /* Fuerza Bruta */
  for (long long i = 1; i <= r; i++) {
    if (simular(i, asteroides)) {
      std::cout << i << '\n';
      return 0;
    }
  }
  return 0;
}
