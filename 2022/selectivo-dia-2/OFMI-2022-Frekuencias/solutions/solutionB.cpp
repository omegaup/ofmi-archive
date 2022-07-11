#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "frekuencias.h"

int frekuenciaAB(const std::vector<int>& s) {
  int n = s.size();
  // Precalculate c
  std::vector<int> c(n, 0);
  for (int i = 0; i < n; ++i) {
    c[i] += s[i];
    if (i > 0) {
      c[i] += c[i - 1];
    }
  }
  int res = 0;
  int lastA = -1, lastB = -1;
  int minC = 0, lastIndexTried = -1;
  for (int j = 0; j < n; ++j) {
    if (s[j] == 1) {
      lastA = j;
    } else {
      lastB = j;
    }
    while (lastIndexTried + 1 < lastA && lastIndexTried + 1 < lastB) {
      lastIndexTried++;
      minC = std::min(minC, c[lastIndexTried]);
    }
    if (lastA > -1 && lastB > -1) {
      res = std::max(res, c[j] - minC);
    }
  }
  return res;
}

int frekuencia(int N, char S[]) {
  int ans = 0;
  for (char a = 'a'; a <= 'z'; ++a) {
    for (char b = 'a'; b <= 'z'; ++b) {
      if (a == b) {
        continue;
      }
      std::vector<int> s;
      for (int i = 0; i < N; ++i) {
        if (S[i] == a) {
          s.push_back(1);
        } else if (S[i] == b) {
          s.push_back(-1);
        }
      }
      ans = std::max(ans, frekuenciaAB(s));
    }
  }
  return ans;
}
