#include <iostream>
#include <vector>

constexpr long long kInf = 1e18;

long long TiempoMinimo(int n, int k, const std::vector<int>& a) {
  if (!n) return 0;

  long long min = kInf;
  for (int i = std::min(k + 1, n); i; --i)
    min = std::min(TiempoMinimo(n - i, k, a) + a[n - 1], min);
  return min;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n + 1);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  std::cout << TiempoMinimo(n + 1, k, a) << '\n';
  return 0;
}
