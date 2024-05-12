#include <algorithm>
#include <iostream>
#include <vector>

int caos(std::vector<int>& p) {
  int ans = 0;
  for (int i = 0; i < p.size(); i++) {
    int inversiones = 0;

    for (int j = i + 1; j < p.size(); j++) {
      if (p[i] > p[j]) {
        inversiones++;
      }
    }

    if (inversiones > 2) {
      return -1;
    }
    ans += inversiones;
  }
  return ans;
}

int main() {
  // Leemos el valor de n.
  int n;
  std::cin >> n;
  // Leemos el arreglo P.
  std::vector<int> P(n);
  for (int i = 0; i < n; i++) {
    std::cin >> P[i];
  }
  // Calculamos la respuesta.
  std::cout << caos(P) << std::endl;
  return 0;
}
