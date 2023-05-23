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
Si todas las posiciones iniciales son iguales, entonces la respuesta es la
interseccion como en sub1 del extremo derecho con el izquierdo
*/
double reunion(int n, int X[], int V[]) {
  int idR = 0;
  int idL = 0;
  for (int i = 0; i < n; ++i) {
    if (X[i] > X[idR]) {
      idR = i;
    }
    if (X[i] < X[idL]) {
      idL = i;
    }
  }

  return reunionSub1(X[idL], V[idL], X[idR], V[idR]);
}
