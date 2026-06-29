#include <iostream>
#include <queue>

int main() {
  int n;
  std::cin >> n;

  int m = 0;
  std::priority_queue<std::pair<int, int>> pq;

  for (int i = 0; i < n; ++i) {
    int degree;
    std::cin >> degree;
    pq.push({degree, i + 1});
    m += degree;
  }

  std::cout << m / 2 << "\n";

  while (!pq.empty()) {
    auto [d_u, u] = pq.top();
    pq.pop();

    std::vector<std::pair<int, int>> reinsertar(d_u);
    for (int i = 0; i < d_u; ++i) {
      auto [d_v, v] = pq.top();
      pq.pop();

      std::cout << u << " " << v << "\n";
      reinsertar[i] = {d_v - 1, v};
    }

    for (auto& par : reinsertar) pq.push(par);
  }
}
