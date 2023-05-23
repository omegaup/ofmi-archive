#include <algorithm>

#include "reunion.h"

/*
Asumimos que n es igual a 2.
Tomamos x0 < x1, con sus respectivos v0 y v1.
En el tiempo t, p0 = x0 + v0 * t y p1 = x1 - v1 * t.
Queremos saber en que tiempo son iguales, entonces:
x0 + v0 * t = x1 - v1 * t
x1 - x0 = (v0 + v1) * t
t = (x1 - x0) / (v0 + v1)
*/
double reunion(int n, int X[], int V[]) {
  double x0 = X[0];
  double x1 = X[1];
  double v0 = V[0];
  double v1 = V[1];
  if (x0 > x1) {  // Forzamos x0 < x1
    std::swap(x0, x1);
    std::swap(v0, v1);
  }
  return (double)(x1 - x0) / (v0 + v1);
}
