#include <iostream>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    sum += num;
  };
  std::cout << 2 * sum << '\n';
  return 0;
};
