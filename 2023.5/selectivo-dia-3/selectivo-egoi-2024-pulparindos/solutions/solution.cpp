#include <algorithm>
#include <iostream>
#include <vector>

int caos(std::vector<int>& p) {
  int ans = 0;
  for (int n = p.size(); n >= 1; --n) {
    // Busquemos la posición de n
    // Solo vamos a buscar en los últimos 3 elementos
    int pos = n - 1;
    for (int d = 0; d <= 2 && pos > 0 && p[pos] != n; d++, pos--)
      ;
    if (p[pos] != n || n - 1 - pos > 2) {
      // No encontramos el número o está a más de 2 posiciones
      return -1;
    }
    // Vamos a mover el número a la posición n - 1
    while (pos < n - 1) {
      std::swap(p[pos], p[pos + 1]);
      pos++;
      ans++;
    }
  }
  return ans;
}

int main() {
  // Leemos el valor de n
  int n;
  std::cin >> n;
  // Leemos el arreglo P
  std::vector<int> P(n);
  for (int i = 0; i < n; i++) {
    std::cin >> P[i];
  }
  // Calculamos la respuesta
  std::cout << caos(P) << std::endl;
  return 0;
}
