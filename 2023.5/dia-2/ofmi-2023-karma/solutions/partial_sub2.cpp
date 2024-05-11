#include <iostream>

const int MAX_N = 300000;
int A[MAX_N];
bool usado[MAX_N];

int main() {
  // Leemos las variables de entrada n y m.
  int n, m;
  std::cin >> n >> m;

  // Leemos los n elementos del arreglo.
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }

  // Simulamos el proceso: hacemos m iteraciones y para cada una
  // de ellas buscamos el mayor elemento del arreglo que no ha
  // sido previamente usado.
  int idxMayor;
  while (m--) {
    idxMayor = -1;
    for (int i = 0; i < n; i++) {
      if (usado[i]) {
        continue;
      }
      if (idxMayor == -1 or A[i] > A[idxMayor]) {
        idxMayor = i;
      }
    }
    usado[idxMayor] = true;
  }

  if (A[idxMayor] > 0) {
    std::cout << A[idxMayor] << "\n";
  } else {
    std::cout << "sencillo\n";
  }

  return 0;
}
