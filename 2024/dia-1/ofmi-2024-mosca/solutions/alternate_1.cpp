#include <algorithm>
#include <iostream>

const int MAX_N = 2e5;
int nums[MAX_N + 1];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  nums[0] = 0;
  int n, m, q;
  std::cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    std::cin >> nums[i];
  };
  std::cin >> q;
  for (int i = 0; i < q; ++i) {
    int a;
    std::cin >> a;
    std::string answer = "Abeja";
    if (i % 2) {
      answer = "Mosca";
    };
    std::cout << answer << '\n';
  };
  return 0;
}
