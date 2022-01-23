#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* srand, rand */
#include <string.h>

#include <iostream>
#include <vector>

#include "torre.h"

int n, m;
int i_juan, j_juan;      // Juanito
int i_tapia, j_tapia;    // Tapia
int i_espera, j_espera;  // Posicion de espera para Tapia
int movimientos;
bool tapiaAtrapado;
bool movimientoInvalido;
bool llamadaInvalida;

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

const int MOVS[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};

bool esSub1() { return n <= 10; }

bool esSub3() { return n > 1000; }

bool esPosicionValida(int i, int j) {
  return !(i < 1 || j < 1 || i > n || j > m) || (i == 0 && j == 0);
}

bool esMovimientoValido(int i, int j) {
  if (!esPosicionValida(i, j)) {
    return false;
  }
  if (i == 0 && j == 0) {
    // Subir a techo solo si estamos en el piso mas alto
    return i_juan == 1;
  }
  if (i_juan == 0) {
    // Si estabamos en el techo, solo podemos bajar al piso mas alto
    return i == 1;
  }
  // Posicion adyacente
  return abs(i_juan - i) + abs(j_juan - j) == 1;
}

int distJuanito(int i, int j) {
  if (i == 0) {
    return i_juan;
  }
  if (i_juan == 0) {
    return i;
  }
  return abs(i_juan - i) + abs(j_juan - j);
}

int distTorre(int i, int j, int a, int b) {
  return std::min(abs(i - a) + abs(j - b), i + a);
}

bool mismaParidad() {
  return ((i_juan + j_juan) & 1) == ((i_tapia + j_tapia) & 1);
}

/*
Tapia está en i_tapia = 0, j_tapia = 0
Regresamos un número entre 1 y m.
*/
int mueveTapiaTecho() {
  i_tapia = 1;
  // Tapia procura estar en el medio, por si necesita escapar
  j_tapia = (m + 1) / 2;
  if (!mismaParidad()) {
    if (distJuanito(1, j_tapia + 1) > 1) {
      ++j_tapia;
    } else {
      --j_tapia;
    }
  }
  return j_tapia;
}

/*
Tapia y Juanito ninguno está en el techo
y están en casillas con misma paridad
*/
int mueveSeguro() {
  // No me preocupa a dónde moverme
  // Me muevo cerca de (2, (m + 1) / 2) para poder escapar, por si acaso
  int siguiente_movimiento = 0;
  int dist_mov = 2 * (n + m);
  for (int mov = 1; mov <= 4; ++mov) {
    int i_tapia_nuevo = i_tapia + MOVS[mov][0];
    int j_tapia_nuevo = j_tapia + MOVS[mov][1];
    if (i_tapia_nuevo == 0) {
      j_tapia_nuevo = 0;
    }
    if (!esPosicionValida(i_tapia_nuevo, j_tapia_nuevo) ||
        distJuanito(i_tapia_nuevo, j_tapia_nuevo) <= 1) {
      continue;
    }
    int nueva_dist =
        distTorre(i_tapia_nuevo, j_tapia_nuevo, i_espera, j_espera);
    if (nueva_dist < dist_mov) {
      dist_mov = nueva_dist;
      siguiente_movimiento = mov;
    }
  }
  i_tapia += MOVS[siguiente_movimiento][0];
  j_tapia += MOVS[siguiente_movimiento][1];
  if (i_tapia == 0) {
    j_tapia = 0;
  }
  return siguiente_movimiento;
}

int mueveEstrategico() {
  // Estrategia: tratamos de ir al techo
  if (i_tapia <= i_juan || (abs(i_juan - i_tapia) < abs(j_juan - j_tapia) &&
                            distJuanito(i_tapia - 1, j_tapia) > 1)) {
    i_tapia--;
    if (i_tapia == 0) {
      j_tapia = 0;
    }
    return ARRIBA;
  } else if (abs(j_juan - j_tapia) == abs(i_juan - i_tapia)) {
    // Mover horizontal
    if (j_tapia < j_juan) {
      if (j_tapia != 1) {
        j_tapia--;
        return IZQUIERDA;
      }
    } else {
      if (j_tapia != m) {
        j_tapia++;
        return DERECHA;
      }
    }
    if (i_tapia != n) {
      i_tapia++;
      return ABAJO;
    }
  }
  // Vemos si tenemos la IZQUIERDA y DERECHA bloqueada
  bool derBloq = (j_tapia == m || distJuanito(i_tapia, j_tapia + 1) <= 1);
  bool izqBloq = (j_tapia == 1 || distJuanito(i_tapia, j_tapia - 1) <= 1);
  if (derBloq && izqBloq) {
    if (i_tapia == n) {
      // Ya valimos banda
      if (j_tapia == 1) {
        j_tapia++;
        return DERECHA;
      } else {
        j_tapia--;
        return IZQUIERDA;
      }
    } else {
      i_tapia++;
      return ABAJO;
    }
  }
  if (derBloq) {
    j_tapia--;
    return IZQUIERDA;
  }
  if (izqBloq) {
    j_tapia++;
    return DERECHA;
  }
  // Voy hacia donde tenga más espacio de ir
  if (j_tapia - 1 > m - j_tapia) {
    j_tapia--;
    return IZQUIERDA;
  } else {
    j_tapia++;
    return DERECHA;
  }
}

int mueveInteligente() {
  // Hora de mover a Tapia
  if (i_tapia == 0 && j_tapia == 0) {
    // Caso tapia está en el techo
    return mueveTapiaTecho();
  } else {
    if (!mismaParidad() && i_juan > 0) {
      return mueveSeguro();
    } else {
      return mueveEstrategico();
    }
  }
}

bool esMovimientoValidoTapia(int i, int j) {
  if (!esPosicionValida(i, j)) {
    return false;
  }
  return i_juan != i || j_juan != j;
}

int mueveTorpe() {
  if (i_tapia == 0) {
    // Tapia está en el techo
    while (true) {
      int columna = rand() % m + 1;
      if (esMovimientoValidoTapia(1, columna)) {
        i_tapia = 1;
        j_tapia = columna;
        return j_tapia;
      }
    }
  } else {
    while (true) {
      int mov = rand() % 4 + 1;
      int i_tapia_nuevo = i_tapia + MOVS[mov][0];
      int j_tapia_nuevo = j_tapia + MOVS[mov][1];
      if (i_tapia_nuevo == 0) {
        j_tapia_nuevo = 0;
      }
      if (esMovimientoValidoTapia(i_tapia_nuevo, j_tapia_nuevo)) {
        i_tapia = i_tapia_nuevo;
        j_tapia = j_tapia_nuevo;
        return mov;
      }
    }
  }
}

int mueve(int i, int j) {
  if (movimientoInvalido || tapiaAtrapado || llamadaInvalida) {
    llamadaInvalida = true;
    return -1;
  }
  movimientos++;
  if (!esMovimientoValido(i, j)) {
    movimientoInvalido = true;
    return -1;
  }
  i_juan = i;
  j_juan = j;
  if (i_juan == i_tapia && j_juan == j_tapia) {
    // Has atrapado a Tapia
    tapiaAtrapado = true;
    return 0;
  }
  // En sub1 tiro una moneda para ver si tapia se mueve torpe o listo
  if (esSub1() && (rand() % 10 < 9)) {
    return mueveTorpe();
  } else {
    return mueveInteligente();
  }
}

// Cuántos movimientos necesito para encerrarlo
// Ya sin subir al techo
int minMovsEncierra(int i1, int j1, int i2, int j2) {
  // Toma el lado donde esta Tapia
  int dist_opt = j1 < j2 ? m - j1 : j1 - 1;
  if (i2 - i1 > abs(j2 - j1) + 1) {
    // Tapia puede moverse al lado que más le guste
    dist_opt = std::max(m - j1, j1 - 1);
  }
  return (n - i1) + dist_opt;
}

// Cuantos movimientos es el mínimo que atrapo a tapia
// Si juanito está en el techo y tapia en la (i, j)
int minMovsBaja(int i, int j) {
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
  return 1 + minMovsEncierra(1, jj, i, j);
}

int minMovsSubeBaja(int i1, int j1, int i2, int j2) {
  if (i1 + 1 > i2) {
    return i1 + n + (m + 1) / 2;
  }
  // Calculemos los pasos que podrá hacer tapia
  int d = std::min(i1, abs((m + 1) / 2 - j2));
  if (j2 < (m + 1) / 2) {
    i2 += d;
  } else {
    i2 -= d;
  }
  // nos falta movernos i_juan-d
  // no importa realmente a dónde nos vamos verticalmente
  if ((i1 - d) & 1) {
    if (i2 == n) {
      i2--;
    } else {
      i2++;
    }
  }
  return i1 + minMovsBaja(i2, j2);
}

int minMovs(int i1, int j1, int i2, int j2) {
  if (distTorre(i1, j1, i2, j2) == 1) {
    return 1;
  }
  if (i1 == 0) {
    // Ya esta en el techo
    return minMovsBaja(i2, j2);
  }
  if ((((i1 + j1) & 1) != ((i2 + j2) & 1)) && abs(j1 - j2) <= i2 - i1 + 1) {
    // Tenemos distinta paridad y ya lo tenemos encerrado
    return std::min(minMovsEncierra(i1, j1, i2, j2),
                    minMovsSubeBaja(i1, j1, i2, j2));
  }
  // Juanito debe ir al techo y atrapar
  return minMovsSubeBaja(i1, j1, i2, j2);
}

float score(int i1, int j1, int i2, int j2) {
  if (llamadaInvalida || movimientoInvalido || !tapiaAtrapado) {
    return 0;
  }
  int esperados = minMovs(i1, j1, i2, j2);
  if (!esSub3() || movimientos <= esperados) {
    // No importa el número de movimientos para atrapar a tapia
    return 1;
  }
  long double a = -0.65 / log(m);
  long double b = pow(m, -1.38);
  long double p = a * log(b * (long double)(movimientos - esperados));
  // Para que el mínimo en el score no de puntos fraccionales entonces
  // 0.4 * p debe ser un número de 2 cifras
  p = std::max((long double)(0.0), p);
  p *= 0.4;
  // round two decimals
  p = ((int)(p * 100 + 0.5)) / 100.0;
  p /= 0.4;
  return p;
}

int main() {
  std::cin >> n >> m;
  std::cin >> i_juan >> j_juan;
  std::cin >> i_tapia >> j_tapia;

  int _i1 = i_juan, _j1 = j_juan;
  int _i2 = i_tapia, _j2 = j_tapia;
  i_espera = 2, j_espera = (m + 1) / 2;

  /* initialize random seed: special for the sub1 case*/
  srand(n + m + i_juan + j_juan + i_tapia + j_tapia);
  juega(n, m, i_juan, j_juan, i_tapia, j_tapia);
  long double p = printf("%.3f\n", score(_i1, _j1, _i2, _j2));
  return 0;
}
