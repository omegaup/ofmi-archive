#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;
  int unos = 0;

  for (int i = 0; i < n; ++i) {
    int u;
    std::cin >> u;
    if (u == 1) {
      unos++;
    }
  }

  std::cout << std::max(unos - 1, 1) << "\n";
  return 0;
}
