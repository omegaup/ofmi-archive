#include <climits>
#include <iostream>

int main() {
  int n, x, ans = INT_MAX;
  std::cin >> n;

  for (int i = 0; i < n; i++) {
    std::cin >> x;
    ans = std::min(ans, x);
  }

  std::cout << ans << '\n';

  return 0;
}
