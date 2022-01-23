#include <math.h>

#include <iostream>

#include "torre.h"

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

// Cuántos movimientos necesito para encerrarlo
// Ya sin subir al techo
int minMovsEncierra(int n, int m, int i_juan, int j_juan, int i_tapia,
                    int j_tapia) {
  // Toma el lado donde esta Tapia
  int dist_opt = j_juan < j_tapia ? m - j_juan : j_juan - 1;
  if (i_tapia - i_juan > abs(j_tapia - j_juan) + 1) {
    // Tapia puede moverse al lado que más le guste
    dist_opt = std::max(m - j_juan, j_juan - 1);
  }
  return (n - i_juan) + dist_opt;
}

// Cuantos movimientos es el mínimo que atrapo a tapia
// Si juanito está en el techo y tapia en la (i, j)
int minMovsBaja(int n, int m, int i, int j) {
  int jj = (m + 1) / 2;
  while (i - 1 < abs(j - jj) || (((1 + jj) & 1) != ((i + j) & 1))) {
    // Me acerco a tapia
    if (jj <= j) {
      jj++;
    } else {
      jj--;
    }
  }
  if (j < (m + 1) / 2) {
    j++;
  } else if (j > (m + 1) / 2) {
    j--;
  } else if (i == n) {
    i--;
  } else {
    i++;
  }
  return 1 + minMovsEncierra(n, m, 1, jj, i, j);
}

int minMovsSubeBaja(int n, int m, int i_juan, int j_juan, int i_tapia,
                    int j_tapia) {
  if (i_juan + 1 > i_tapia) {
    return i_juan + (m + 1) / 2;
  }
  // Calculemos los pasos que podrá hacer tapia
  int d = std::min(i_juan, abs((m + 1) / 2 - j_tapia));
  if (j_tapia < (m + 1) / 2) {
    j_tapia += d;
  } else {
    j_tapia -= d;
  }
  // nos falta movernos i_juan-d
  // no importa realmente a dónde nos vamos verticalmente
  if ((i_juan - d) & 1) {
    if (i_tapia == n) {
      i_tapia--;
    } else {
      i_tapia++;
    }
  }

  return i_juan + minMovsBaja(n, m, i_tapia, j_tapia);
}

bool convieneTecho(int n, int m, int i_juan, int j_juan, int i_tapia,
                   int j_tapia) {
  if ((((i_juan + j_juan) & 1) == ((i_tapia + j_tapia) & 1)) ||
      (i_tapia <= i_juan) ||
      (abs(i_juan - i_tapia) < abs(j_juan - j_tapia) - 1)) {
    return true;
  }
  return minMovsSubeBaja(n, m, i_juan, j_juan, i_tapia, j_tapia) <
         minMovsEncierra(n, m, i_juan, j_juan, i_tapia, j_tapia);
}

void juega(int n, int m, int i_juan, int j_juan, int i_tapia, int j_tapia) {
  while (true) {
    // MOVER A JUANITO
    if (i_juan == 0) {
      // Estamos en (0,0)
      i_juan = 1;
      j_juan = (m + 1) / 2;
      while (abs(i_juan - i_tapia) < abs(j_juan - j_tapia) ||
             (((i_juan + j_juan) & 1) != ((i_tapia + j_tapia) & 1))) {
        // Me acerco a tapia
        if (j_juan <= j_tapia) {
          j_juan++;
        } else {
          j_juan--;
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
      if (convieneTecho(n, m, i_juan, j_juan, i_tapia, j_tapia)) {
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
