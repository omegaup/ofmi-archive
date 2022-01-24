#include <algorithm>
#include <climits>
#include <iostream>

int main() {
  // Leemos n y k
  int n, k;
  std::cin >> n >> k;

  // Leemos el arreglo
  int T[n + 1];
  for (int i = 1; i <= n; i++) {
    std::cin >> T[i];
  }
  // Ordenamos el arreglo
  std::sort(T + 1, T + n + 1);

  // Buscamos la mejor i que minimice (T_i - T_1) + (T_N - T_{i + 1})
  int menor_costo = INT_MAX;
  for (int i = 1; i < n; i++) {
    menor_costo = std::min(menor_costo, T[i] - T[1] + T[n] - T[i + 1]);
  }

  std::cout << menor_costo << '\n';
}
