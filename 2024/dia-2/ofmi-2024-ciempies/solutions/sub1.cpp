/* Subtarea 1
Si todo A_i es par, basta con ordenar el arreglo e imprimirlo
ordenado.
*/
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  // Leemos n
  int n;
  std::cin >> n;
  // Leemos el arreglo
  std::vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  // Ordenamos el arreglo
  std::sort(A.begin(), A.end());

  // Imprimimos el arreglo
  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << "\n";
  return 0;
}
