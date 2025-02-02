// Chafa (no debería dar puntos): checamos si la última expedición
// intersecta, si sí, entonces hacemos pop de todo.
#include <iostream>
#include <vector>

typedef std::pair<int, int> pii;

bool intersectan(const pii& a, const pii& b) {
  if (a.first < b.first) {
    return a.second > b.second;
  } else if (b.first < a.first) {
    return intersectan(b, a);
  }
  return false;
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<pii> activas;

  for (int i = 0; i < q; ++i) {
    int u, v;
    std::cin >> u >> v;
    int res = 0;
    while (!activas.empty() && activas.back().first == u) {
      activas.pop_back();
    }
    if (!activas.empty() && intersectan({u, v}, activas.back())) {
      res = activas.size();
      activas.clear();
    }
    activas.push_back({u, v});
    std::cout << res << std::endl;
  }
}
