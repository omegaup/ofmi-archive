#include <algorithm>
#include <iostream>
#include <vector>

// Nuevo tipo de dato para almacenar un valor del arreglo
// y su índice.
struct Elemento {
  int val;
  int idx;
};

// Comparador para ordenar los elementos del arreglo
bool comparaElementos(Elemento a, Elemento b) { return a.val < b.val; }

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int N, M, K;
  std::cin >> N >> M >> K;
  std::vector<Elemento> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i].val;
    A[i].idx = i;
  }

  // Ordenamos los elementos del arreglo por valor, de menor a mayor
  sort(A.begin(), A.end(), comparaElementos);

  // Usaremos los M * K elementos más pequeños
  int lim = M * K;
  std::vector<bool> usar(N, false);
  for (int i = 0; i < lim; i++) {
    usar[A[i].idx] = true;
  }

  // Creamos las particiones asegurándonos de que en cada una se usen
  // K de los elementos elegidos en el paso anterior
  int i = 0;
  std::vector<int> particiones;
  for (int p = 0; p < M; p++) {
    int tam = 0;
    while (tam < K) {
      tam += usar[i];
      i++;
    }
    particiones.push_back(i);
  }

  // Imprimimos los índices de las particiones
  for (int i = 0; i < M - 1; i++) {
    std::cout << particiones[i] << " ";
  }
  std::cout << "\n";
  return 0;
}
