#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

#include "compresion.h"

typedef std::pair<int, int> pii;

// Solution O(n^2)
int compresion(int n, int m, int A[]) {
  std::sort(A, A + n);
  std::vector<pii> B;
  for (int i = 0; i < n; i++) {
    if (i == 0 || A[i] != A[i - 1]) {
      B.push_back({A[i], 1});
    } else {
      B[B.size() - 1].second++;
    }
  }
  int best = 0;
  int bestA = -1, bestB = -1;

  for (int i = 0; i < B.size(); i++) {
    int suma = 0;
    for (int j = 0; j < m && i + j < B.size(); ++j) {
      suma += B[i + j].second;
    }
    if (suma > best) {
      best = suma;
      bestA = B[i].first;
      if (i + m - 1 < B.size()) {
        bestB = B[i + m - 1].first;
      } else {
        bestB = B[B.size() - 1].first;
      }
    }
  }
  aplasta(bestA, bestB);
  return n - best;
}
