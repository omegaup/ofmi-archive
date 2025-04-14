// Sub3: La respuesta siempre es un sufijo del arreglo.

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

  int escuadron = 0, ans = 0, inicio = 0, fin = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (T[i] >= k) {
      escuadron++;
    }

    if (escuadron > (n - i) / 2) {
      ans = escuadron;
      inicio = i + 1;
      fin = n;
    }
  }

  if (ans == 0) {
    std::cout << "-1\n";
  } else {
    std::cout << inicio << " " << fin << "\n";
  }
  return 0;
}
