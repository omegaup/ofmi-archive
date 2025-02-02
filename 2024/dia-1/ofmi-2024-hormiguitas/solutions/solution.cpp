#include <iostream>
#include <set>
#include <vector>

std::set<std::pair<int, int>> filas;

int Expedicion(int hormiguero, int platillo) {
  // Buscamos el primer hormiguero con indice mayor o igual.
  auto inicio = filas.upper_bound({hormiguero, 0});

  // Si hay una fila que empieza en este hormiguero, la borramos y volvemos a
  // buscar el siguiente hormiguero con indice estrictamente mayor.
  if (inicio != filas.end() && inicio->first == hormiguero) {
    filas.erase(inicio);
    inicio = filas.upper_bound({hormiguero, 0});
  }

  // Mientras exista una fila hacia adelante cuyo objetivo sea menor al platillo
  // por el que esta expedicion va, esa fila tendra que ser retirada.
  // Despues del while, `fin` queda en la primer posicion mayor o `filas.end()`.
  auto fin = inicio;
  while (fin != filas.end() && fin->second < platillo) ++fin;

  // Mientras exista una fila atras cuyo objetivo sea mayor al platillo por el
  // que esta expedicion va, esa fila tendra que ser retirada.
  while (inicio != filas.begin()) {
    auto previo = inicio;
    if ((--previo)->second <= platillo) break;
    inicio = previo;
  }

  // La funcion `distance` cuenta cuantas posiciones hay en [inicio, fin).
  // Nota que el fin del rango NO esta incluido en las posiciones.
  int filas_retiradas = std::distance(inicio, fin);

  // Borramos todas las posiciones desde `inicio` hasta antes de `fin`.
  filas.erase(inicio, fin);

  filas.insert({hormiguero, platillo});
  return filas_retiradas;
}

int main() {
  int n, m, q;
  std::cin >> n >> m >> q;

  for (int i = 0; i < q; ++i) {
    int u, v;
    std::cin >> u >> v;
    std::cout << Expedicion(u, v) << '\n';
  }
}
