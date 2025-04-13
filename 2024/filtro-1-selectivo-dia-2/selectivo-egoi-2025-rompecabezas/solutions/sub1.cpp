// Sub 1: Se hace una simulación de las operaciones con una cubeta.

#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, q;
  std::cin >> n >> q;

  std::vector<int> aparicion(std::min(n, q) + 1);

  while (q--) {
    char tipo;
    int ri;
    std::cin >> tipo >> ri;

    if (tipo == '+') {
      if (ri < aparicion.size()) aparicion[ri]++;
    } else {
      if (ri < aparicion.size()) aparicion[ri]--;

      int cand = -1;
      for (int i = 1; i <= n; i++) {
        if (aparicion[i] == 0) {
          cand = i;
          break;
        }
      }
      std::cout << cand << "\n";
    }
  }
}
