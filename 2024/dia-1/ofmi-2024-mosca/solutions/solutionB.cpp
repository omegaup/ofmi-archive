#include <iostream>

int main() {
  int n, m;
  std::cin >> n >> m;

  int grupos_amigas[m];
  for (int i = 0; i < m; ++i) std::cin >> grupos_amigas[i];

  int q;
  std::cin >> q;

  int grupo_actual = 0;
  int inicio_grupo = 1;

  for (int i = 0; i < q; ++i) {
    int indice_amiga;
    std::cin >> indice_amiga;

    while (inicio_grupo + grupos_amigas[grupo_actual] <= indice_amiga) {
      inicio_grupo += grupos_amigas[grupo_actual++];
    }
    std::cout << ((grupo_actual % 2) ? "Abeja\n" : "Mosca\n");
  }
  return 0;
}
