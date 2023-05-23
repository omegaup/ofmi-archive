/*
Esta solución asume que en algun punto del tiro, pasamos por una x entera
Esto es falso, debería dar unicamente puntaje cuando michmo tira dentro de la
mesa En ese caso, sí es cierto que está dentro si y solo si pega en x = N / 2
*/
#include "michmo.h"

// Si vemos la mesa N en el eje x y M en el eje y
// entonces A / B quiere decir por cada B unidades en el eje x
// se mueve A unidades en el eje y
void michmo(int N, int M, int P, int A, int B) {
  float m = (float)A / B;
  bool toco = false;

  for (int x = 0; x <= N; x++) {
    float y = m * x + P;
    if (x >= N / 2 && 0 <= y && y <= M) {
      toco = true;
      break;
    }
  }

  if (!toco) {
    terminar();
  }
  int p = N * m + P;
  devolver(p, p, N);
}
