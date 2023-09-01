#include "michmo.h"

void michmo(int N, int M, int P, int A, int B) {
  bool toca = false;
  double m = (double)A / B;
  {  // Checamos si la linea toca el segmento (n/2, 0) - (n/2, m)
    double y = (N / 2) * m + P;
    if (0 <= y && y <= M) {
      toca = true;
    }
  }
  {  // Checamos si la linea toca el segmento (n/2, 0) - (n, 0)
    double x = (-P) / m;
    if (N / 2 <= x && x <= N) {
      toca = true;
    }
  }
  {  // Checamos si la linea toca el segmento (n/2, m) - (n, m)
    double x = (M - P) / m;
    if (N / 2 <= x && x <= N) {
      toca = true;
    }
  }

  if (!toca) {
    terminar();
  } else {
    int p = N * m + P;
    devolver(p, p, N);
  }
}
