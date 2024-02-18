#include <iostream>
#include <vector>

long long maxSubarraySum(const std::vector<int> &nums) {
  long long maxi = 0, maxine = 0;
  for (int num : nums) {
    maxine += num;
    if (maxi < maxine) {
      maxi = maxine;
    };
    if (num == 0) {
      maxine = 0;
    };
  };
  return maxi;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  for (int i = 0; i < n; i++) {
    std::cin >> nums[i];
  };
  while (n--) {
    int t;
    std::cin >> t;
    nums[t] = 0;
    std::cout << maxSubarraySum(nums) << '\n';
  };
  return 0;
};