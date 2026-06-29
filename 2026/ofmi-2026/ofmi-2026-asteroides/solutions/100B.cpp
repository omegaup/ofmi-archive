#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  int masa[n];

  for (int i = 0; i < n; i++) {
    std::cin >> masa[i];
  }

  int carga_inicial = 0;
  int suma_cargas = 0;

  std::sort(masa, masa + n);

  for (int i = 0; i < n; i++) {
    if (masa[i] > suma_cargas) {
      int diferencia = masa[i] - suma_cargas;
      carga_inicial = std::max(carga_inicial, diferencia);
    }

    suma_cargas += masa[i];
  }

  std::cout << carga_inicial << "\n";
}
