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

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (masa[j] < masa[i]) std::swap(masa[i], masa[j]);
    }
  }

  bool carga_inicial_suficiente = false;
  int respuesta;

  for (int i = 0; i < n; i++) {
    int carga_actual = masa[i];
    carga_inicial_suficiente = true;

    for (int i = 0; i < n; i++) {
      if (carga_actual < masa[i]) {
        carga_inicial_suficiente = false;
        break;
      }

      carga_actual += masa[i];
    }

    if (carga_inicial_suficiente) {
      int sobrante = masa[i];
      carga_actual = masa[i];

      for (int j = 0; j < n; j++) {
        sobrante = std::min(sobrante, carga_actual - masa[j]);
        carga_actual += masa[j];
      }
      respuesta = masa[i] - sobrante;

      break;
    }
  }

  std::cout << respuesta << "\n";
}
