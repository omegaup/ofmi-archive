#include <iostream>

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;  // n = 1

  // Solo hay 1 día
  int cantidad_tipos;
  std::cin >> cantidad_tipos;

  // total_tipos es cuantos tipos se encontraron en el único día
  int total_tipos = cantidad_tipos;

  // Leer los códigos de los tipos
  for (int j = 0; j < cantidad_tipos; j++) {
    int id;
    std::cin >> id;  // no hace falta guardarlos específicamente
  }

  // Resolvemos cada consulta
  while (q--) {
    int k;
    std::cin >> k;

    if (k == 0) {
      // Todos se encontraron >= 0
      std::cout << m << "\n";
    } else if (k == 1) {
      // Solo los que se encontraron
      std::cout << total_tipos << "\n";
    }
    // (Si k > 1, esta solución no contempla ese caso,
    //  pero no es un asunto de formateo.)
  }

  return 0;
}
