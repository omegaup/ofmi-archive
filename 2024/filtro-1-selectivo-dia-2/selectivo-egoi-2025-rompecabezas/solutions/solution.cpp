#include <iostream>
#include <queue>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  std::priority_queue<int> faltantes;
  std::vector<int> conteo(std::min(n, q));
  for (int i = 0; i < std::min(n, q); ++i) faltantes.push(-i);

  for (int i = 0; i < q; ++i) {
    int r;
    char tipo;
    std::cin >> tipo >> r;

    if (tipo == '+') {
      if (--r < q) ++conteo[r];
    } else {
      if (--r < q && !--conteo[r]) faltantes.push(-r);
      while (!faltantes.empty() && conteo[-faltantes.top()]) faltantes.pop();
      std::cout << (faltantes.empty() ? -1 : -faltantes.top() + 1) << '\n';
    }
  }
}
