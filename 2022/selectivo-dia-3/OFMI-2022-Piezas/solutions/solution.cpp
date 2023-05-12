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

int palabraFavorita(int n, char s[], int m, char piezas[]) {
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
