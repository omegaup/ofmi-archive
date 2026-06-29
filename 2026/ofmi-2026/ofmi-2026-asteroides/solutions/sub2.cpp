#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> masa(n);

  for (int i = 0; i < n; i++) {
    std::cin >> masa[i];
  }

  if (n == 1) {
    std::cout << masa[0] << "\n";
    return 0;
  }

  if (n == 2) {
    if (masa[1] < masa[0]) std::swap(masa[0], masa[1]);
    std::cout << std::max(masa[0], masa[1] - masa[0]) << "\n";
    return 0;
  }

  // ordenar el arreglo
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (masa[j] < masa[i]) std::swap(masa[i], masa[j]);
    }
  }

  bool carga_inicial_suficiente = false;
  int carga_inicial = 1;

  while (!carga_inicial_suficiente) {
    int carga_actual = carga_inicial;
    carga_inicial_suficiente = true;

    for (int i = 0; i < n; i++) {
      if (carga_actual < masa[i]) {
        carga_inicial++;
        carga_inicial_suficiente = false;
        break;
      }

      carga_actual += masa[i];
    }
  }

  std::cout << carga_inicial << "\n";
}
