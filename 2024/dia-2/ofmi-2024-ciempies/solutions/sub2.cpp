/* Subtarea 2
Dado que ya está ordenado, podemos primero
imprimir únicamente los zapatos de número par y
en otra pasada imprimimos los números impares
*/
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

  // Imprimimos los números pares
  for (int i = 0; i < n; ++i) {
    if ((A[i] % 2) == 0) {
      std::cout << A[i] << " ";
    }
  }
  // Imprimimos los números impares
  for (int i = 0; i < n; ++i) {
    if ((A[i] % 2) == 1) {
      std::cout << A[i] << " ";
    }
  }
  std::cout << "\n";
  return 0;
}
