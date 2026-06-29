/*  Probar simulacion con busqueda binaria */
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

  /* Busqueda Binaria */
  long long ans = 0;
  while (l <= r) {
    long long m = l + (r - l) / 2;

    if (simular(m, asteroides)) {
      ans = m;
      r = m - 1;
    } else
      l = m + 1;
  }

  std::cout << ans << '\n';
  return 0;
}
