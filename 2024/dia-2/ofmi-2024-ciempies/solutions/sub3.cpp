/* Sub3
Intentamos aplicar algún método de ordenamiento cuadrático
que podamos definir nosotras mismas qué va antes.
*/
#include <iostream>
#include <vector>

// Regresa true si el `zapatoA` "va antes" que `zapatoB`
bool vaAntes(int zapatoA, int zapatoB) {
  if ((zapatoA % 2) == (zapatoB % 2)) {
    // Si tienen la misma paridad,
    return zapatoA < zapatoB;
  }
  // Si no tienen la misma paridad, el que es par
  // va antes
  return (zapatoA % 2) == 0;
}

int main() {
  // Leemos n
  int n;
  std::cin >> n;
  // Leemos el arreglo
  std::vector<int> A(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  // Para cada elemento del arreglo, lo pongo en su lugar.
  for (int i = 0; i < n; i++) {
    // Estamos acomodando el elemento i.
    int actual = A[i];
    // Esta indica el siguiente elemento contra el que
    // vamos a ver si actual "va antes de" él.
    int j;
    // Encuentra el primer lugar donde ya no "voy antes".
    for (j = i - 1; j >= 0; j--) {
      // ¿Actual "va antes de" el siguiente elemento por comparar?
      if (vaAntes(actual, A[j])) {
        // Tengo que mover A[j] a la derecha.
        A[j + 1] = A[j];
      } else {
        // Ya no voy antes de A[j].
        break;
      }
    }
    // Nos ponemos juntito después.
    A[j + 1] = actual;
  }

  // Imprimimos el arreglo
  for (int i = 0; i < n; ++i) {
    std::cout << A[i] << " ";
  }
  std::cout << "\n";
  return 0;
}
