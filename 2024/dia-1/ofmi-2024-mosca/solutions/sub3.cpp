// Subtarea 3: q <= 300
// En esta subtarea, la cantidad de amigas es muy grande, entonces no
// podemos guardar si es mosca o abeja por persona. Pero como la cantidad
// de preguntas es poca, entonces, podemos buscar en que grupo pertenece
// si recorremos todos los grupos.
#include <iostream>

const int MaxM = 2e5 + 10;
int M;
int grupo_de_amigas[MaxM];

bool es_mosca(int amiga) {
  int amigas_de_otros_grupos = 0;
  bool si_es_mosca = true;
  for (int i = 0; i < M; ++i) {
    if (amiga <= amigas_de_otros_grupos + grupo_de_amigas[i]) {
      // La amiga pertenece al grupo [i]
      return si_es_mosca;
    }
    // La amiga no pertenece al grupo [i]
    // Agregamos las amigas del grupo [i] a [amigas_de_otros_grupos]
    amigas_de_otros_grupos += grupo_de_amigas[i];
    // Cambiamos de mosca a (no mosca) o viceversa
    si_es_mosca = !si_es_mosca;
  }
  // Si llegamos aqui, significa que la amiga no estuvo en ningun grupo
  // Eso es imposible, pero regresamos [si_es_mosca] de todos modos
  return si_es_mosca;
}

int main() {
  int N;
  std::cin >> N >> M;
  for (int i = 0; i < M; ++i) {
    std::cin >> grupo_de_amigas[i];
  }

  int Q;
  std::cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int amiga;
    std::cin >> amiga;
    // Checamos la posicion de la amiga para ver si es
    // mosca o (no mosca), es decir, abeja
    if (es_mosca(amiga)) {
      std::cout << "Mosca\n";
    } else {
      std::cout << "Abeja\n";
    }
  }
  return 0;
}
