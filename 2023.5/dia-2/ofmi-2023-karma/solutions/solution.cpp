// Solución. Encontrar el m-esimo elemento más grande en un arreglo de n
// elementos. Si es positivo, imprimirlo.
#include <algorithm>
#include <iostream>

const int MAXN = 1000002;
int a[MAXN];

int main() {
  // Leemos las variables de entrada n y m.
  int n, m;
  std::cin >> n >> m;

  // Leemos los n elementos del arreglo.
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }

  // Ordenamos el arreglo de mayor a menor.
  std::sort(a, a + n);
  std::reverse(a, a + n);

  if (a[m - 1] > 0) {
    // Si el m-esimo elemento es positivo, lo imprimimos.
    std::cout << a[m - 1] << std::endl;
  } else {
    std::cout << "sencillo" << std::endl;
  }

  return 0;
}
