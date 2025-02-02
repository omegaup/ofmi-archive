#include <iostream>

const int MaxN = 100005;
bool se_encontro[MaxN];

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;  // q = 1, k_1 = 1

  // Leemos n días
  for (int i = 0; i < n; i++) {
    int cantidad_tipos;
    std::cin >> cantidad_tipos;

    for (int j = 0; j < cantidad_tipos; j++) {
      int codigo_flor;
      std::cin >> codigo_flor;
      se_encontro[codigo_flor] = true;
    }
  }

  // Contamos cuántos tienen se_encontro[codigo_flor] = true
  int total_encontrados = 0;
  for (int codigo_flor = 1; codigo_flor <= m; codigo_flor++) {
    if (se_encontro[codigo_flor]) {
      total_encontrados++;
    }
  }

  // Solo hay 1 consulta, k = 1
  // Respuesta = total_encontrados
  // (No hace falta leer de cin, pero lo hacemos para ajustar el formato)
  int k;
  std::cin >> k;
  std::cout << total_encontrados << "\n";

  return 0;
}
