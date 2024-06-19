#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n;
  std::cin >> n;

  std::vector<int> arr(n);
  for (int& a : arr) std::cin >> a;

  int total_intercambios = 0;

  // Vamos a emular un insertion sort desde el fin del arreglo hacia atras; en
  // la `k`-esima iteracion, los ultimos `k` elementos ya estan ordenados.
  for (int k = 1; k < n; ++k) {
    int intercambios_actuales = 0;

    // Para asegurar que en la siguiente iteracion los ultimos `k + 1` elementos
    // estaran ordenados, recorremos el elemento en la posicion `n - k - 1` a la
    // derecha mientras el siguiente elemento en el arreglo sea menor.
    for (int j = n - k; j < n && arr[j - 1] > arr[j]; ++j) {
      std::swap(arr[j - 1], arr[j]);

      // Hemos realizado un intercambio mas para el `j`-esimo elemento, si ya se
      // realizaron mas de 2 intercambios entonces no hay solucion.
      if (++intercambios_actuales > 2) {
        std::cout << "-1\n";
        return 0;
      }
    }

    // Acumulamos el numero de intercambios realizados.
    total_intercambios += intercambios_actuales;
  }

  std::cout << total_intercambios << "\n";
  return 0;
}
