#include <iostream>

const int MAX_N = 300000;
int A[MAX_N];

int main() {
  // Leemos las variables de entrada n y m.
  int n, m;
  std::cin >> n >> m;

  // Leemos los n elementos del arreglo.
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }

  // Solución para la subtarea 2: buscar el mayor elemento del arreglo y
  // verificar
  int idxMayor = 0;
  for (int i = 1; i < n; i++) {
    if (A[i] > A[idxMayor]) {
      idxMayor = i;
    }
  }

  if (A[idxMayor] > 0) {
    std::cout << A[idxMayor] << "\n";
  } else {
    std::cout << "sencillo\n";
  }

  return 0;
}
