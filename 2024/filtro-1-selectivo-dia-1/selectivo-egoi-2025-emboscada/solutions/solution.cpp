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

  long long max_ti = *std::max_element(t.begin(), t.end());
  long long l = 0, r = max_ti * k;
  while (l < r) {
    long long m = (l + r) / 2;

    long long aeronaves_inspeccionadas = 0;
    for (int ti : t) {
      aeronaves_inspeccionadas += m / ti + 1;
      if (aeronaves_inspeccionadas > k) break;
    }

    if (aeronaves_inspeccionadas <= k)
      l = m + 1;
    else
      r = m;
  }

  for (int ti : t) k -= (l + ti - 1) / ti;
  for (int i = 0; i < n; ++i) {
    if (l % t[i]) continue;

    if (!k--) {
      std::cout << l << ' ' << i + 1 << '\n';
      return 0;
    }
  }
}
