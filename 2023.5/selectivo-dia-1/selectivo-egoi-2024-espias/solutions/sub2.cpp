#include <iostream>
#include <vector>

struct Grafo {
  Grafo(int n) : nodo_adyacente(n), visitado(n, false) {}

  void AgregarArista(int u, int v) { nodo_adyacente[u] = v; }

  // Este método marca todos los nodos que se pueden visitar desde `u`.
  void VisitarAdyacentes(int u) {
    while (!visitado[u]) {
      visitado[u] = true;
      u = nodo_adyacente[u];
    }
  }

  // Calcula el minimo numero de llamadas a `VisitarAdyacentes` necesarias para
  // que todos los nodos en el grafo sean marcados como visitados.
  int MinimoParaCubrirGrafo() {
    int minimo_para_cubrir_grafo = 0;

    for (int u = 0; u < visitado.size(); ++u) {
      if (!visitado[u]) {
        ++minimo_para_cubrir_grafo;
        VisitarAdyacentes(u);
      }
    }
    return minimo_para_cubrir_grafo;
  }

  std::vector<int> nodo_adyacente;
  std::vector<bool> visitado;
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  Grafo espias(n);

  for (int i = 0; i < n; ++i) {
    int u;
    std::cin >> u;
    espias.AgregarArista(i, u - 1);
  }

  std::cout << espias.MinimoParaCubrirGrafo() << '\n';
  return 0;
}
