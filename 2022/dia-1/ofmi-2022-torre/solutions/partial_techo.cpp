#include <iostream>

#include "torre.h"

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

void juega(int n, int m, int i_juan, int j_juan, int i_tapia, int j_tapia) {
  while (true) {
    // MOVER A JUANITO
    if (i_juan == 0) {
      // Estamos en (0,0)
      i_juan = 1;
      if (i_tapia & 1) {
        // Nos movemos a su misma columna
        j_juan = j_tapia;
      } else {
        // Nos movemos una a lado
        if (j_tapia - 1 < m - j_tapia) {
          j_juan = j_tapia + 1;
        } else {
          j_juan = j_tapia - 1;
        }
      }
    } else if (abs(i_juan - i_tapia) + abs(j_juan - j_tapia) == 1) {
      if (i_juan < i_tapia) {
        i_juan++;
      } else if (i_juan > i_tapia) {
        i_juan--;
        if (i_juan == 0) {
          j_juan = 0;
        }
      } else if (j_juan < j_tapia) {
        j_juan++;
      } else {
        j_juan--;
      }
    } else {
      // Checamos si tenemos la misma paridad
      if ((((i_juan + j_juan) & 1) == ((i_tapia + j_tapia) & 1)) ||
          (i_tapia <= i_juan) ||
          (abs(i_juan - i_tapia) < abs(j_juan - j_tapia) - 1)) {
        // Necesitamos la misma paridad, por lo que tenemos que subir
        i_juan--;
        if (i_juan == 0) {
          j_juan = 0;
        }
      } else if (i_juan < n &&
                 (abs(i_juan - i_tapia) >= abs(j_juan - j_tapia))) {
        i_juan++;
      } else {
        // tengo que seguirlo horizontal
        if (j_juan < j_tapia) {
          j_juan++;
        } else {
          j_juan--;
        }
      }
    }

    int m = mueve(i_juan, j_juan);
    if (m == 0 || m == -1) {
      break;
    }
    if (i_tapia == 0) {
      i_tapia = 1;
      j_tapia = m;
    } else if (m == ARRIBA) {
      i_tapia--;
      if (i_tapia == 0) {
        j_tapia = 0;
      }
    } else if (m == ABAJO) {
      i_tapia++;
    } else if (m == DERECHA) {
      j_tapia++;
    } else {  // Izquierda
      j_tapia--;
    }
  }
}
