// Subtarea 2: n <= 200,000
// En esta subtarea, la cantidad de personas en la fila es suficientemente
// chicas como para guardar si es mosca o abeja en un arreglo y responder
// las preguntas en constante.
#include <iostream>

const int MaxN = 1e7;
bool es_mosca[MaxN];

int main() {
  int N, M;
  std::cin >> N >> M;

  int ultima_posicion = 0;
  bool si_es_mosca = false;
  for (int i = 0; i < M; ++i) {
    int grupo_de_amigas;
    std::cin >> grupo_de_amigas;

    // Cambiamos de mosca a (no mosca), o de (no mosca) a mosca
    si_es_mosca = !si_es_mosca;
    for (int j = 0; j < grupo_de_amigas; ++j) {
      // Marcamos a todas las del grupo como [si_es_mosca]
      es_mosca[++ultima_posicion] = si_es_mosca;
    }
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int amiga;
    std::cin >> amiga;
    // Checamos la posicion de la amiga para ver si es
    // mosca o (no mosca), es decir, abeja
    if (es_mosca[amiga]) {
      std::cout << "Mosca\n";
    } else {
      std::cout << "Abeja\n";
    }
  }
  return 0;
}
