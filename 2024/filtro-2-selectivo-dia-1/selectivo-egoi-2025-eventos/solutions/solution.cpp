#include <algorithm>
#include <iostream>
#include <vector>

struct Evento {
  bool operator<(const Evento& otro) const { return s < otro.s; }

  int s, e, v;
};

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<Evento> eventos(n);
  for (auto& [s, e, v] : eventos) std::cin >> s >> e >> v;
  std::sort(eventos.begin(), eventos.end());

  std::vector<int> dp(n + 1);
  for (int i = n - 1; i >= 0; --i) {
    int siguiente_evento =
        std::lower_bound(eventos.begin(), eventos.end(), Evento{eventos[i].e}) -
        eventos.begin();
    dp[i] = std::max(dp[i + 1], dp[siguiente_evento] + eventos[i].v);
  }
  std::cout << dp[0] << '\n';
}
