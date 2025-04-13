// Sub1: Cuadratica probando todos los posibles inicios.

#include <algorithm>
#include <iostream>
#include <string>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n, k;
  std::cin >> n >> k;

  std::string ruleta;
  std::cin >> ruleta;

  int max_premios = 0;
  for (int i = 0; i < n; ++i) {
    int intentos = 0;
    for (int j = 0; j < n; ++j) {
      intentos += (ruleta[(i + j) % n] == 'S') ? 1 : 0;
      if (intentos == k) break;
      max_premios = std::max(max_premios, j - intentos + 1);
    }
  }
  std::cout << max_premios << '\n';
}
