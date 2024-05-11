#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  int N, C;
  std::cin >> N >> C;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  // Variable para guardar cuantos grupos están pendientes
  // de abordar.
  long long pendientes = 0;
  for (int i = 0; i < N; i++) {
    // Agregamos los grupos que llegaron en la hora i a los pendientes.
    pendientes += (long long)A[i];

    // Calculamos el tiempo de espera.
    long long espera = pendientes / (long long)C;
    if (espera < (long long)(N - i)) {
      std::cout << espera << " ";
    } else {
      std::cout << "-1 ";
    }

    // Simulamos el abordaje de C grupos.
    pendientes -= (long long)C;
    pendientes = std::max((long long)0, pendientes);
  }
  std::cout << "\n";

  return 0;
}