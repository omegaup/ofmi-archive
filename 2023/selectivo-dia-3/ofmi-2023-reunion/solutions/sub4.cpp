#include <algorithm>

#include "reunion.h"

double reunionSub1(double x0, double v0, double x1, double v1) {
  if (x0 > x1) {  // Forzamos x0 < x1
    std::swap(x0, x1);
    std::swap(v0, v1);
  }
  return (double)(x1 - x0) / (v0 + v1);
}

/*
Regresando a la sub2, nos damos cuenta que la solución es el máximo
de los tiempos de intersección de cada par de perritos.
*/
double reunion(int n, int X[], int V[]) {
  double ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = std::max(ans, reunionSub1(X[i], V[i], X[j], V[j]));
    }
  }
  return ans;
}
