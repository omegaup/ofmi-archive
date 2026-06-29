#include <algorithm>
#include <iostream>

int main() {
  int n;
  std::cin >> n;

  int M[n];
  for (int i = 0; i < n; i++) {
    std::cin >> M[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (M[j] < M[i]) std::swap(M[i], M[j]);
    }
  }

  int carga_actual = 0, carga_inicial = 0;
  for (int i = 0; i < n; i++) {
    if (carga_actual < M[i]) {
      carga_inicial += M[i] - carga_actual;
      carga_actual = M[i];
    }
    carga_actual += M[i];
  }
  std::cout << carga_inicial << '\n';
}
