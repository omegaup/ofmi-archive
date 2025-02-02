#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  std::vector<int> arr(n + 1);
  for (auto& a : arr) std::cin >> a;

  std::vector<int> prefix_sum(n);
  for (int i = 0; i < s; ++i) prefix_sum[i] = arr[i];
  for (int i = s; i < n; ++i) prefix_sum[i] = arr[i] + prefix_sum[i - s];

  int answer = 0;
  for (int i = n - 1; i >= 0; --i) {
    answer = std::max(answer, prefix_sum[i] + (t ? arr[i + 1] : 0));
    if (i + s < n) arr[i] += arr[i + s];
  }
  std::cout << answer << '\n';
}
