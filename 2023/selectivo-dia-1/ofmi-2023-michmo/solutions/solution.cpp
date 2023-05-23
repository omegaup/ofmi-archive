#include "michmo.h"

double evaluar(double pendiente, double x, double constante) {
  return pendiente * x + constante;
}

void michmo(int N, int M, int P, int A, int B) {
  if (B == 0) {
    // No deberia pasar
    terminar();
    return;
  }

  double pendiente = (double)A / B;
  if (0 <= P && P <= M) {
    // Debe estar entre (N/2, 0) y (N/2, M)
    double punto = evaluar(pendiente, N / 2, P);
    if (punto < 0 || M < punto) {
      // No toca el area
      terminar();
      return;
    }
  } else if (P < 0) {
    // Puede pasar entre (N/2, M) y (N/2, 0)
    double punto = evaluar(pendiente, N / 2, P);
    if (M < punto) {
      // No toca el area
      terminar();
      return;
    }
    // Puede pasar entre (N/2, 0) y (N, 0)
    punto = evaluar(pendiente, N, P);
    if (punto < 0) {
      // No toca el area
      terminar();
      return;
    }
  } else {
    // P > M
    // Puede pasar entre (N, M) y (N/2, M)
    double punto = evaluar(pendiente, N, P);
    if (punto > M) {
      // No toca el area
      terminar();
      return;
    }
    // Puede pasar entre (N/2, M) y (N/2, 0)
    punto = evaluar(pendiente, N / 2, P);
    if (punto < 0) {
      // No toca el area
      terminar();
      return;
    }
  }

  // Regresar pelota y que pase por (N/2, 1)
  int nuevoP = evaluar(pendiente, N, P);
  devolver(nuevoP, nuevoP - 1, N / 2);
}
