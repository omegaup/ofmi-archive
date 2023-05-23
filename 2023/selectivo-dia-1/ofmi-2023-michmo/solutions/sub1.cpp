#include "michmo.h"

void michmo(int N, int M, int P, int A, int B) {
  // Subtarea 1: Checar si esta en la mesa
  if (0 <= P && P <= M) {
    // Si esta dentro
    devolver(0, 0, 1);
  } else {
    terminar();
  }
}
