#include <algorithm>

#include "unodos.h"

// Para esta subtarea la respuesta es 0.5 para todos los nodos excepto
// Los que no tienen aristas, para los cuales la respuesta es 0
// Notar que en este caso siempre es posible hacer la asignacion
bool unoDos(int n, int m, int U[], int V[], int T[]) {
  bool tieneArista[n + 1];
  std::fill(tieneArista + 1, tieneArista + n + 1, false);
  for (int i = 0; i < m; ++i) {
    tieneArista[U[i]] = true;
    tieneArista[V[i]] = true;
  }
  for (int nodo = 1; nodo <= n; ++nodo) {
    if (!tieneArista[nodo]) {
      asigna(nodo, 0);
    } else {
      asigna(nodo, 0.5);
    }
  }
  return true;
}
