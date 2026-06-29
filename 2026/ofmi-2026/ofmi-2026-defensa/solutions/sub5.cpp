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

  std::vector<int> cubeta(k + 1);
  for (int i = 1; i <= n; ++i) ++cubeta[sectores[i] += sectores[i - 1]];
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
