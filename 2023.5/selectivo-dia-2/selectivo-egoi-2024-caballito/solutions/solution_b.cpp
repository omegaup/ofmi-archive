#include <iostream>
#include <queue>
#include <vector>

// Valor sentinela para representar que un nodo no es accesible.
const int kInaccesible = 1e9;

struct Grafo {
  Grafo(int n) : lista_adyacencia(n) {}

  void AgregarArista(int u, int v) {
    lista_adyacencia[u].push_back(v);
    lista_adyacencia[v].push_back(u);
  }

  // Calcula la distancia minima desde el nodo `origen` a todos los demas nodos.
  // Regresa un arreglo de tamano `n` donde la `i`-esima posicion representa la
  // distancia minima desde el nodo `origen` hasta el nodo `i`.
  std::vector<int> BFS(int origen) {
    std::queue<int> cola;

    // Inicializamos la distancia a todos los nodos como inaccesible.
    // El numero de nodos `n` es el tamano de la lista de adyacencia.
    std::vector<int> distancias(lista_adyacencia.size(), kInaccesible);

    // El unico nodo accesible al inicio es `origen`.
    cola.push(origen);
    distancias[origen] = 0;

    while (!cola.empty()) {
      int u = cola.front();
      cola.pop();

      for (int v : lista_adyacencia[u]) {
        if (distancias[v] == kInaccesible) {
          // Si el nodo `v` aun no es accesible, actualizamos la distancia
          // minima a este y lo insertamos al final de la cola.
          cola.push(v);
          distancias[v] = distancias[u] + 1;
        }
      }
    }
    return distancias;
  }

  std::vector<std::vector<int>> lista_adyacencia;
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  long long x, y, z;
  std::cin >> x >> y >> z;

  // Creamos un grafo de `n` nodos.
  Grafo grafo(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    std::cin >> a >> b;
    grafo.AgregarArista(a - 1, b - 1);
  }

  // Sacamos las distancias minimas desde `A`, `B` y `N`.
  auto distancias_desde_a = grafo.BFS(0);
  auto distancias_desde_b = grafo.BFS(1);
  auto distancias_desde_n = grafo.BFS(n - 1);

  // Calculamos la energia necesaria para ir directamente de `A` y `B` a `N` sin
  // moverse juntos para usarla como referencia de la menor energia.
  long long menor_energia =
      distancias_desde_a[n - 1] * x + distancias_desde_b[n - 1] * y;

  // Para cada nodo `i`, vamos a calcular la energia necesaria para juntar a `A`
  // y `B` en ese nodo y llevarlos el resto del camino juntos hasta `N`.
  for (int i = 0; i < n - 1; ++i) {
    menor_energia = std::min(menor_energia, distancias_desde_a[i] * x +
                                                distancias_desde_b[i] * y +
                                                distancias_desde_n[i] * z);
  }
  std::cout << menor_energia << '\n';
  return 0;
}
