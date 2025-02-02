#include <iostream>

const int MaxTipos = 1e5 + 5;

int encontradas_por_tipo[MaxTipos];
int encontradas_por_dia[MaxTipos];

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  // Leer las veces que se encontraron los tipos de flor
  for (int i = 0; i < n; i++) {
    int cantidad_tipos;
    std::cin >> cantidad_tipos;

    for (int j = 0; j < cantidad_tipos; j++) {
      int codigo_flor;
      std::cin >> codigo_flor;
      encontradas_por_tipo[codigo_flor]++;
    }
  }

  // Contar la cantidad de tipos encontrados una cierta cantidad de veces
  for (int i = 1; i <= m; i++) {
    encontradas_por_dia[encontradas_por_tipo[i]]++;
  }

  // Acumular los tipos con cantidad de encontradas iguales o mayores a un valor
  // dado ¿Por qué empezar desde MaxTipos - 2? Si un tipo se encontró por x
  // cantidad de días, también aparecerá en la respuesta de x-1
  for (int i = MaxTipos - 2; i >= 0; i--) {
    encontradas_por_dia[i] += encontradas_por_dia[i + 1];
  }

  // Responder las consultas
  for (int i = 0; i < q; i++) {
    int cantidad_dias;
    std::cin >> cantidad_dias;
    std::cout << encontradas_por_dia[cantidad_dias] << "\n";
  }

  return 0;
}
