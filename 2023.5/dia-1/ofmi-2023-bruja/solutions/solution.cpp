#include <iostream>
#include <set>

/**
  La idea de la solucion es contar la cantidad de elementos diferentes.

  Un set de la STL es un contenedor que elimina elementos repetidos,
  que es justo lo que necesitamos.
*/

int main() {
  /**
    Las siguientes tres lineas no son parte de la solucion,
    solo optimizan el tiempo que el programa tarda en las
    entradas y salidas (cin/cout).
  */
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  /// Aqui empieza la solucion.
  /// Declaramos un set que contiene enteros.
  std::set<int> diferentes;
  int n;
  std::cin >> n;  /// Lee la primera linea.
  /**
    Hacemos un ciclo que itera n veces.
    La variable n pasa por los valores n, n - 1, n - 2, ..., 0.
    Cuando n llega a 0, el ciclo se detiene porque 0 es falso en C++.
  */
  while (n--) {
    int x;
    /// Lee cada uno de los n enteros de la segunda linea.
    std::cin >> x;

    /// Inserta cada uno de los n enteros de la segunda linea
    /// en el set en tiempo O(log T), siendo T el tamanio de 'diferentes'
    diferentes.insert(x);
  }  /// Tiempo total: O(n log n)

  /// La respuesta es la cantidad de elementos diferentes,
  /// esto es, el tamanio del set.
  std::cout << diferentes.size() << '\n';
}
