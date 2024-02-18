#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    int num;
    std::cin >> num;
    nums[i] = num;
    sum += num;
  };
  while (n--) {
    int t;
    std::cin >> t;
    sum -= nums[t];
    std::cout << sum << '\n';
  };
  return 0;
};