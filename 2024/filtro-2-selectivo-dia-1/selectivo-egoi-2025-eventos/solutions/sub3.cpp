// Sub3: DP donde el estado es el tiempo actual. Para determinarr cuales eventos
// podemos usar en cada tiempo, podemos guardarlos similar a como se guardan las
// aristas en un grafo y maximizamos acorde a cuales fines tenemos disponibles.

#include <algorithm>
#include <iostream>
#include <vector>

constexpr int kMaxE = 1e6;

int dp[kMaxE + 1];
std::vector<std::pair<int, int>> finales[kMaxE + 1];

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  for (int i = 0; i < n; ++i) {
    int s, e, v;
    std::cin >> s >> e >> v;
    if (kMaxE < s) continue;
    finales[s].push_back({e, v});
  }

  for (int i = kMaxE - 1; i >= 0; --i) {
    dp[i] = dp[i + 1];
    for (auto [e, v] : finales[i]) dp[i] = std::max(dp[i], dp[e] + v);
  }
  std::cout << dp[0] << '\n';
}
