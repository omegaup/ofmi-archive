// Subtarea 2: t = 1.
// Esto es, solo vuela por un segundo.
#include <iostream>

int main() {
  int t, h;
  std::cin >> t >> h;
  if (t > 1) {
    // Si [t] > 1, suponemos que es la subtarea 1, donde
    // la respuesta es [t].
    std::cout << t << "\n";
    return 0;
  }

  // Si [t] = 1, entonces es la subtarea 2. Leemos la única
  // altura donde vamos a volar.
  int altura;
  std::cin >> altura;

  // Leemos los pretzels disponibles
  int pretzel[h];
  for (int i = 0; i < h; ++i) {
    std::cin >> pretzel[i];
  }

  // Los pretzels que usaríamos en [altura] esta en la posición
  // [altura - 1] de nuestro arreglo de pretzels. No tenemos
  // que hacer mas porque solo volaremos por un segundo.
  std::cout << pretzel[altura - 1] << "\n";
  return 0;
}
