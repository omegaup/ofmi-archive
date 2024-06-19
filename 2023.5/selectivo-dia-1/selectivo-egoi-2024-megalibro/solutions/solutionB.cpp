#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 200000

long long A[MAX_N];
long long dp[MAX_N];

struct DPValue {
  long long val;
  long long idx;
};

struct Comparator {
  bool operator()(const DPValue& a, const DPValue& b) { return b.val <= a.val; }
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  std::priority_queue<DPValue, std::vector<DPValue>, Comparator> pq;

  for (int i = 0; i < n; i++) {
    if (i >= k) {
      DPValue mejor = pq.top();
      while (mejor.idx < i - k) {
        pq.pop();
        mejor = pq.top();
      }

      dp[i] = mejor.val;
    }

    if (i < n - 1) {
      DPValue nuevo;
      nuevo.idx = i + 1;
      nuevo.val = dp[i] + A[i + 1];
      pq.push(nuevo);
    }
  }

  std::cout << dp[n - 1] << '\n';

  return 0;
}
