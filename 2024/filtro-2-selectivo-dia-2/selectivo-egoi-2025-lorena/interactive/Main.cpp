#include <iostream>
#include <vector>

#include "ruleta.h"

std::vector<int> arreglo;
int llamadas_restantes;

int pregunta(int p) {
  if (!llamadas_restantes--) {
    std::cout << "0.0" << std::endl;
    std::exit(0);
  }
  return (0 <= p && p < arreglo.size()) ? arreglo[p] : -1;
}

int main() {
  int n, x, a;
  std::cin >> n >> x;

  int indice_x = -1;
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    if (a == x) indice_x = i;
    arreglo.push_back(a);
  }

  std::cin >> llamadas_restantes;
  std::cout << ((indice_x == encuentra(x, n)) ? "1.0" : "0.0") << std::endl;
}
