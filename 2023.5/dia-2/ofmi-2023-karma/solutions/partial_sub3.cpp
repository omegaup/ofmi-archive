#include <iostream>

const int MAX_N = 300000;
int ceros, unos;

int main() {
  // Leemos las variables de entrada n y m.
  int n, m;
  std::cin >> n >> m;

  // Leemos los n elementos del arreglo; solo contamos cuantos ceros
  // y cuantos unos hay en el arreglo.
  int num;
  for (int i = 0; i < n; ++i) {
    std::cin >> num;
    if (num == 1) {
      unos++;
    } else {
      ceros++;
    }
  }

  if (m <= unos) {
    std::cout << "1\n";
  } else {
    std::cout << "sencillo\n";
  }

  return 0;
}
