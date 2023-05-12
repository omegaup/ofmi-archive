#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#include "piezasdefomi.h"

std::map<char, int> fillBucket(int n, char s[], std::map<char, char>& parent) {
  std::map<char, int> res;
  for (int i = 0; i < n; ++i) {
    char c = s[i];
    if (parent.count(c) > 0) {
      c = parent[c];
    }
    res[c]++;
  }
  return res;
}

int miPalabraFavorita(int n, char s[], int m, char piezas[]) {
  std::map<char, char> parent;
  // Agregamos transiciones
  parent['q'] = 'p';
  parent['d'] = 'b';
  parent['z'] = 's';
  std::map<char, int> bucketS = fillBucket(n, s, parent);
  std::map<char, int> bucketPiezas = fillBucket(m, piezas, parent);
  int res = m;
  for (auto it : bucketS) {
    res = std::min(res, bucketPiezas[it.first] / it.second);
  }
  return res;
}

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
  std::cout << (miPalabraFavorita(n, ss, m, p) == palabraFavorita(n, ss, m, p)
                    ? "1.00"
                    : "0.00")
            << std::endl;
  return 0;
}
