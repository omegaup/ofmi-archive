#include <fstream>
#include <iostream>
#include <set>
#include <vector>

int main() {
  int n;
  std::vector<int> degrees;

  // Leer los degrees de los nodos en el caso.
  {
    std::ifstream input("data.in", std::ifstream::in);

    input >> n;
    degrees = std::vector<int>(n);
    for (int& degree : degrees) input >> degree;
  }

  int m;
  std::set<std::pair<int, int>> conexiones;

  if (!(std::cin >> m)) {
    std::cerr << "Linea 1: Error al leer numero de conexiones\n";
    std::cout << "0.0\n";
    return 0;
  }

  for (int i = 0; i < m; ++i) {
    int u, v;
    if (!(std::cin >> u >> v)) {
      std::cerr << "Linea " << i + 2 << ": Error al leer conexion\n";
      std::cout << "0.0\n";
      return 0;
    }

    if (u < 1 || n < u || v < 1 || n < v) {
      std::cerr << "Linea " << i + 2 << ": Indice fuera de rango\n";
      std::cout << "0.0\n";
      return 0;
    }

    if (u == v) {
      std::cerr << "Linea " << i + 2 << ": Conexion \"self-loop\" invalida\n";
      std::cout << "0.0\n";
      return 0;
    }

    if (v < u) std::swap(u, v);

    if (conexiones.find({u, v}) != conexiones.end()) {
      std::cerr << "Linea " << i + 2 << ": Conexion repetida\n";
      std::cout << "0.0\n";
      return 0;
    }

    conexiones.insert({u, v});
    --degrees[u - 1];
    --degrees[v - 1];
  }

  std::string trailing;
  if (std::cin >> trailing) {
    std::cerr << "Contenido no esperado en la salida\n";
    std::cout << "0.0\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (degrees[i]) {
      std::cerr << "El degree de la estrella " << i + 1 << " es incorrecto\n";
      std::cout << "0.0\n";
      return 0;
    }
  }

  // Todo salio bien, accepted!
  std::cout << "1.0\n";
}
