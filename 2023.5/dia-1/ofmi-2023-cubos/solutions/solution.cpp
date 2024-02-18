#include "cubos.h"

int matriz[3][1000][1000];

const int FRENTE = 0;  // X, Y
const int ARRIBA = 1;  // X, Z
const int LADO = 2;    // Y, Z

void bloque(int x, int y, int z) {
  matriz[FRENTE][x][y] = 1;
  matriz[ARRIBA][x][z] = 1;
  matriz[LADO][y][z] = 1;

  ponerBloque(x, y, z);
}

void cubo(int N) {
  int lastz = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int y = j;
      bool p = false;
      for (int k = 0; k < N; k++) {
        int z = (lastz + k) % N;

        if (matriz[FRENTE][i][y] == 0 && matriz[ARRIBA][i][z] == 0 &&
            matriz[LADO][y][z] == 0) {
          bloque(i, y, z);
          lastz = z + 1;
          p = true;

          break;
        }
      }
    }
  }
}