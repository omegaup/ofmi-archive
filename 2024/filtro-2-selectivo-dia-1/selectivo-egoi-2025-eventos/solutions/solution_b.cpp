#include <algorithm>
#include <iostream>
#include <vector>

struct Event {
  int s, e, v;
};

bool compareEvents(const Event& a, const Event& b) {
  if (a.e != b.e) {
    return a.e < b.e;
  }
  return a.s < b.s;
}

// Función para encontrar el último evento antes de events[i]
// que no se solapa con events[i]
int findClosestNonConflicting(const std::vector<Event>& events, int i) {
  int begin = 0, end = i - 1;
  int result = -1;

  while (begin <= end) {
    int mid = begin + (end - begin) / 2;
    if (events[mid].e <= events[i].s) {
      result = mid;
      begin = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return result;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);

  int n;
  std::cin >> n;

  std::vector<Event> events(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> events[i].s >> events[i].e >> events[i].v;
  }

  std::sort(events.begin(), events.end(), compareEvents);

  std::vector<long long> dp(n);

  dp[0] = events[0].v;
  for (int i = 1; i < n; ++i) {
    long long happiness_if_included = events[i].v;
    int closest_non_conflicting = findClosestNonConflicting(events, i);

    if (closest_non_conflicting != -1) {
      happiness_if_included += dp[closest_non_conflicting];
    }

    long long happiness_if_not_included = dp[i - 1];

    dp[i] = std::max(happiness_if_included, happiness_if_not_included);
  }
  std::cout << dp[n - 1] << std::endl;
}
