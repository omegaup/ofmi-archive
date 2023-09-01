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
Asumimos que n es igual a 3.
Tomamos x0 < x1 < x2, con sus respectivos v0, v1 y v2.
La solución es el tiempo máximo de intersectar x0 con x1, x0 con x2 y x1 con x2.
*/
double reunion(int n, int X[], int V[]) {
  return std::max({reunionSub1(X[0], V[0], X[1], V[1]),
                   reunionSub1(X[0], V[0], X[2], V[2]),
                   reunionSub1(X[1], V[1], X[2], V[2])});
}
