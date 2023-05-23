#include "michmo.h"

float evaluar(float pendiente, float x, float constante) {
  return pendiente * x + constante;
}

void michmo(int N, int M, int P, int A, int B) {
  // Subtarea 2: Tiro certero
  float pendiente = (float)A / B;
  int punto = evaluar(pendiente, N, P);
  devolver(punto, punto - 1, N);
}
