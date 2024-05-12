#include <algorithm>
#include <iostream>
#include <vector>

struct Elemento {
  // Comparador personalizado para ordenar los elementos por menor valor.
  bool operator<(const Elemento& otro) const { return valor < otro.valor; }

  // El indice y valor del elemento en el elementoseglo original.
  int indice, valor;
};

// Comparador personalizado para ordenar los elementos por indice.
bool ComparaPorIndice(const Elemento& a, const Elemento& b) {
  return a.indice < b.indice;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, m, k;
  std::cin >> n >> m >> k;

  std::vector<Elemento> elementos(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> elementos[i].valor;

    // Guardamos el indice indexado desde 1.
    elementos[i].indice = i + 1;
  }

  // Ordenamos los elementos por valor de menor a mayor.
  std::sort(elementos.begin(), elementos.end());

  // La solucion va a usar los `m * k` elementos con menor valor; para imprimir
  // la respuesta necesitamos ordenar los primeros `m * k` elementos por indice,
  // ya que los indices quedan desordenados despues del primer `sort`.
  std::sort(elementos.begin(), elementos.begin() + m * k, ComparaPorIndice);

  // Para imprimir las particiones, vamos a agrupar los elementos de la solucion
  // en `m` grupos de `k` elementos cada uno; el indice del ultimo elemento de
  // un grupo nos indica donde hacer cada particion (excepto la ultima).
  for (int i = 1; i < m; ++i) {
    std::cout << elementos[i * k - 1].indice << ' ';
  }
  std::cout << '\n';
  return 0;
}
