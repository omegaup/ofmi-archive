#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> sectores(n + 2);
  for (int i = 0; i < k; ++i) {
    int l, r, e;
    std::cin >> l >> r >> e;
    --sectores[r + 1];
    ++sectores[l];
  }

  int q, x;
  std::cin >> q >> x;

  int acumulado = 0, respuesta = 0;
  for (int i = 1; i <= n; ++i) {
    acumulado += sectores[i];
    if (x <= acumulado) ++respuesta;
  }
  std::cout << respuesta << "\n";
}
