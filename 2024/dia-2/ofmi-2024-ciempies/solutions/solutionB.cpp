#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int zapatos[n];
  for (int i = 0; i < n; ++i) std::cin >> zapatos[i];

  // Ordenamos todos los zapatos por talla.
  std::sort(zapatos, zapatos + n);

  // Filtramos los zapatos con talla par primero.
  for (int i = 0; i < n; ++i) {
    if (!(zapatos[i] % 2)) std::cout << zapatos[i] << ' ';
  }

  // Despues, filtramos los zapatos con talla impar.
  for (int i = 0; i < n; ++i) {
    if (zapatos[i] % 2) std::cout << zapatos[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}
