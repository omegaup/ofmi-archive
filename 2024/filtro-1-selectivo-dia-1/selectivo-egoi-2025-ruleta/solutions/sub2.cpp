// Sub2: Para k = 1 encontrar la mayor cantidad de premios consecutivos.

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

  // Duplicamos la ruleta para simular la circularidad.
  ruleta += ruleta;

  int max_premios = 0, premios_actuales = 0;
  for (char c : ruleta) {
    if (c == 'P') {
      ++premios_actuales;
      continue;
    }

    max_premios = std::max(max_premios, std::min(premios_actuales, n));
    premios_actuales = 0;
  }
  std::cout << std::max(max_premios, std::min(premios_actuales, n)) << '\n';
}
