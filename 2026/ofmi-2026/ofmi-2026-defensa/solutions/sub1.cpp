#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> sectores(n + 1);
  while (k--) {
    int l, r, e;
    std::cin >> l >> r >> e;
    for (int i = l; i <= r; ++i) ++sectores[i];
  }

  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::cin >> x;

    int conteo = 0;
    for (int i = 1; i <= n; ++i)
      if (sectores[i] >= x) ++conteo;
    std::cout << conteo << "\n";
  }
}
