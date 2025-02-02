// Subtarea 1: m = 2
// En esta subtarea, para cada pregunta simplemente hay que comparar
// si la amiga a_i está en el primer grupo o no.
#include <iostream>
#include <vector>

int main() {
  // Leemos n y m
  int n, m;
  std::cin >> n >> m;

  // Leemos el arreglo P de m enteros
  std::vector<int> P(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> P[i];
  }

  // Leemos q
  int q;
  std::cin >> q;
  for (int j = 0; j < q; ++j) {
    int ai;
    std::cin >> ai;
    // Imprimiremos mosca sí está en el primer grupo de amigas,
    // o abeja en caso contrario.
    if (ai <= P[0]) {
      std::cout << "Mosca\n";
    } else {
      std::cout << "Abeja\n";
    }
  }
  return 0;
}
