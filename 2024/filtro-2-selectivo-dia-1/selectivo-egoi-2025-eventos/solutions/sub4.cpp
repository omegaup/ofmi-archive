// Sub4: Ordenamos los eventos por inicio y hacemos una DP de dos dimensiones;
// la primera dimension determina cual fue el ultimo evento al que se asistio,
// la segunda el evento actual sobre el que estamos decidiendo.

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

  std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));
  for (int p = n - 1; p >= 0; --p) {
    for (int i = n - 1; i >= p; --i) {
      dp[p][i] = dp[p][i + 1];
      if (!p || eventos[p - 1].e <= eventos[i].s)
        dp[p][i] = std::max(dp[p][i + 1], dp[i + 1][i + 1] + eventos[i].v);
    }
  }
  std::cout << dp[0][0] << '\n';
}
