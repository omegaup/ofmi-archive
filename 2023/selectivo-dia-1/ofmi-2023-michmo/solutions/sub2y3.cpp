#include "michmo.h"

float evaluar(float pendiente, float x, float constante) {
  return pendiente * x + constante;
}

void michmo(int N, int M, int P, int A, int B) {
  if (0 <= P && P <= M) {
    // Posiblemente subtarea 2: Inicia en la mesa
    float pendiente = (float)A / B;
    float superior = (float)(M - P) / (N / 2);
    float inferior = (float)-P / (N / 2);
    if (inferior <= pendiente && pendiente <= superior) {
      // Si entra al area
      int punto = evaluar(pendiente, N, P);
      devolver(punto, punto - 1, N);
    } else {
      // Nunca entra
      terminar();
    }
  } else {
    // Intenta subtarea 3: Tiro certero
    float pendiente = (float)A / B;
    int punto = evaluar(pendiente, N, P);
    devolver(punto, punto - 1, N);
  }
}
