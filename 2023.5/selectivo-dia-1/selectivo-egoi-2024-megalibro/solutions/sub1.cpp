#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> a(n);
  for (int& a_i : a) std::cin >> a_i;

  long long sum = 0;
  for (int i = k; i < n; i += k + 1) sum += a[i];
  std::cout << sum << '\n';
  return 0;
}
