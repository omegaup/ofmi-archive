#include <iostream>
#include <vector>

int main() {
  int t, h;
  std::cin >> t >> h;

  // Declaramos arreglo de pretzels
  // + 1 para empezar en el índice 1 y poder
  // mapear directamente las alturas a una posición
  std::vector<int> pretzels(h + 1);
  std::vector<int> altura(t);

  for (int i = 0; i < t; i++) {
    std::cin >> altura[i];
  }

  for (int i = 1; i <= h; i++) {
    std::cin >> pretzels[i];
  }

  int altura_i, pretzels_i;
  int pretzels_total = 0;  // Máximo es 10^8 = 10^5 * 10^3 < 10^9
  for (int i = 0; i < t; i++) {
    // Obtenemos la altura a_i que voló en el tiempo i-ésimo
    altura_i = altura[i];
    // Obtenemos los pretzels usados por volar h_i
    pretzels_i = pretzels[altura_i];
    // Acumulamos los pretzels totales
    pretzels_total += pretzels_i;
  }

  std::cout << pretzels_total << "\n";

  return 0;
}
