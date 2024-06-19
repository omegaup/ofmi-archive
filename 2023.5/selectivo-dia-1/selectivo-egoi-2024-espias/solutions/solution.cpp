#include <iostream>
#include <vector>

struct Grafo {
  Grafo(int n) : indegree(n), nodo_adyacente(n), visitado(n) {}

  void AgregarArista(int u, int v) {
    // El indegree de un nodo es la cantidad de aristas que llegan a el. Si `u`
    // tiene una arista a `v`, entonces el indegree de `v` aumenta en 1.
    ++indegree[v];
    nodo_adyacente[u] = v;
  }

  // Este metodo marca todos los nodos que se pueden visitar desde `u`.
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

    // Si un nodo tiene indegree 0 significa que ningun otro nodo podra llegar a
    // el, es decir, forzosamente necesitamos `VisitarAdyacentes` desde `u`.
    for (int u = 0; u < indegree.size(); ++u) {
      if (indegree[u] == 0) {
        ++minimo_para_cubrir_grafo;
        VisitarAdyacentes(u);
      }
    }

    // Despues de la cobertura desde los nodos con indegree 0, aun es posible
    // tener componentes sin visitar, esto ocurre cuando una componente es un
    // ciclo; basta con recorrer los ciclos desde cualquiera de sus nodos.
    for (int u = 0; u < visitado.size(); ++u) {
      if (!visitado[u]) {
        ++minimo_para_cubrir_grafo;
        VisitarAdyacentes(u);
      }
    }
    return minimo_para_cubrir_grafo;
  }

  std::vector<int> indegree;
  std::vector<int> nodo_adyacente;
  std::vector<bool> visitado;
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  // Creamos un grafo de `n` nodos.
  Grafo espias(n);

  for (int i = 0; i < n; ++i) {
    int u;
    std::cin >> u;
    espias.AgregarArista(i, u - 1);
  }

  std::cout << espias.MinimoParaCubrirGrafo() << '\n';
  return 0;
}
