// Sub2: Para cada posible rango, calcular si hay mayoria con suma de prefijos.

#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::vector<int> T(n);
  for (int i = 0; i < n; i++) {
    std::cin >> T[i];
  }

  int ans = 0, inicio = 0, fin = 0;
  for (int i = 0; i < n; i++) {
    int escuadron = 0;
    for (int j = i; j < n; j++) {
      if (T[j] >= k) {
        escuadron++;
      }

      if (escuadron > (j - i + 1) / 2 && j - i + 1 > ans) {
        ans = j - i + 1;
        inicio = i + 1;
        fin = j + 1;
      }
    }
  }

  if (ans == 0) {
    std::cout << "-1\n";
  } else {
    std::cout << inicio << " " << fin << "\n";
  }
  return 0;
}
