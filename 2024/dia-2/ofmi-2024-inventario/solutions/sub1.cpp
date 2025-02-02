#include <iostream>

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;  // m = 1

  // Contador de encontradas del único tipo de flor
  int encontradas = 0;

  // Leemos n días
  for (int i = 0; i < n; i++) {
    int cantidad_flores;
    std::cin >> cantidad_flores;

    // Si cantidad_flores > 0, leemos los tipos de flor
    // Solo hay 1 tipo en total, pero si aparece, sumamos 1 a
    // 'encontradas'
    for (int j = 0; j < cantidad_flores; j++) {
      int codigo_flor;
      std::cin >> codigo_flor;
      // El único tipos de flor es el 1, pero aquí incrementamos encontradas de
      // todas formas
      encontradas++;
    }
  }

  // Resolvemos cada consulta
  while (q--) {
    int cantidad_dias;
    std::cin >> cantidad_dias;
    // Solo hay un tipos de flor, respondemos 1 si encontradas >= cantidad_dias,
    // sino 0
    std::cout << ((encontradas >= cantidad_dias) ? 1 : 0) << "\n";
  }

  return 0;
}
