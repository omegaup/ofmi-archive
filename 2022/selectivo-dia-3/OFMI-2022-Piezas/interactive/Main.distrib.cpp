#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#include "piezasdefomi.h"

int main() {
  std::string s, piezas;
  std::cin >> s >> piezas;
  int n = s.size();
  char ss[n];
  for (int i = 0; i < n; ++i) {
    ss[i] = s[i];
  }
  int m = piezas.size();
  char p[m];
  for (int i = 0; i < m; ++i) {
    p[i] = piezas[i];
  }
  std::cout << "Tu programa regresó: " << palabraFavorita(n, ss, m, p)
            << std::endl;
  return 0;
}
