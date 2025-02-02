#include <iostream>
#include <queue>
#include <vector>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  std::vector<int> arr(n);
  for (auto& a : arr) std::cin >> a;

  std::vector<int> prefix_sum(n);
  for (int i = 0; i < s; ++i) prefix_sum[i] = arr[i];
  for (int i = s; i < n; ++i) prefix_sum[i] = arr[i] + prefix_sum[i - s];

  int answer = 0;
  std::priority_queue<std::pair<int, int>> q;

  for (int i = n - 1; i >= 0; --i) {
    while (!q.empty() && q.top().second > i + t) q.pop();
    answer = std::max(answer, prefix_sum[i] + (q.empty() ? 0 : q.top().first));
    if (i + s < n) arr[i] += arr[i + s];
    q.push({arr[i], i});
  }
  std::cout << answer << '\n';
}
