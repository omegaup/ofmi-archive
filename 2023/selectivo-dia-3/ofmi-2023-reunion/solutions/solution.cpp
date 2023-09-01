#include <algorithm>

#include "reunion.h"

bool intersectanRangos(int n, int X[], int V[], double t) {
  double minimo = -1e9, maximo = 1e9;
  for (int i = 0; i < n; ++i) {
    double ini = X[i] - V[i] * t;
    double fin = X[i] + V[i] * t;
    minimo = std::max(minimo, ini);
    maximo = std::min(maximo, fin);
  }
  return minimo <= maximo;
}

double reunion(int n, int X[], int V[]) {
  double low = 0, high = 1e9;
  for (int i = 0; i < 100; ++i) {
    double mid = (low + high) / 2;
    if (intersectanRangos(n, X, V, mid)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  return low;
}
