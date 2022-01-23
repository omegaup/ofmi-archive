#include <iostream>

#include "torre.h"

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

int x_tapia, y_tapia;
int x_juan, y_juan;
int movs[5][2] = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int N, M;

void actualizar_posicion(int& x, int& y, int mov) {
  if (x == 0) {
    // Bajamos del techo; mov es la columna
    x = 1;
    y = mov;
    return;
  }
  // No estamos en el techo
  x += movs[mov][0];
  y += movs[mov][1];
  if (x == 0) {
    // Llegamos al techo
    y = 0;
  }
}

void actualizar_Tapia(int movimiento) {
  // Aplicamos el movimiento a Tapia
  actualizar_posicion(x_tapia, y_tapia, movimiento);
}

void actualizar_Juan(int movimiento) {
  // Aplicamos el movimiento a Juan
  actualizar_posicion(x_juan, y_juan, movimiento);
}

int distancia() {
  if (x_juan == 0 || x_tapia == 0) {
    // Distancia al techo
    return x_juan + x_tapia;
  }
  return std::abs(x_juan - x_tapia) + std::abs(y_juan - y_tapia);
}

bool misma_paridad() { return distancia() % 2 == 0; }

void techo_juan() {
  // A Juan le conviene saltar a la columna de Tapia
  if (x_tapia == 1) {
    // Atrapamos a Tapia
    actualizar_Juan(y_tapia);
    return;
  }

  int limite_escape = x_tapia - 2;
  int izq_valido = std::max(y_tapia - limite_escape, 1);
  int der_valido = std::min(y_tapia + limite_escape, M);
  int opt_dist =
      std::min((M + 1) / 2, std::min(M - izq_valido, der_valido - 1));

  int movimiento;
  if (M - izq_valido == opt_dist) {
    actualizar_Juan(izq_valido);
    movimiento = IZQUIERDA;
  } else if (der_valido - 1 == opt_dist) {
    actualizar_Juan(der_valido);
    movimiento = DERECHA;
  } else {
    // Poner a Juan en el medio
    actualizar_Juan((M + 1) / 2);
    if (y_juan < y_tapia) {
      movimiento = DERECHA;
    } else {
      movimiento = IZQUIERDA;
    }
  }

  if (!misma_paridad()) {
    if (y_juan != 1 && y_juan != M) {
      actualizar_Juan(movimiento);
    } else {
      actualizar_Juan(movimiento == DERECHA ? IZQUIERDA : DERECHA);
    }
  }
}

void acercar_horizontal_Juan() {
  // Acercamos a Juan a la posicion de Tapia
  if (y_juan < y_tapia) {
    actualizar_Juan(DERECHA);
  } else {
    actualizar_Juan(IZQUIERDA);
  }
}

void juega(int n, int m, int i_juan, int j_juan, int i_tapia, int j_tapia) {
  // Guardamos las posiciones de manera global
  N = n;
  M = m;
  x_juan = i_juan;
  y_juan = j_juan;
  x_tapia = i_tapia;
  y_tapia = j_tapia;

  // Empezamos a buscar
  int ultimo_movimiento = 1;
  while (ultimo_movimiento > 0) {
    if (x_juan == 0) {
      // Juan esta en el techo
      techo_juan();
      ultimo_movimiento = mueve(x_juan, y_juan);
    } else {
      if (misma_paridad()) {
        // Hay que cambiar la paridad
        // Juan todavia no esta en el techo
        actualizar_Juan(ARRIBA);
        ultimo_movimiento = mueve(x_juan, y_juan);
      } else {
        // Perseguir a Tapia
        if (x_juan > x_tapia) {
          // Tapia intentara cambiar la paridad
          actualizar_Juan(ARRIBA);
          ultimo_movimiento = mueve(x_juan, y_juan);
        } else if (x_juan == x_tapia) {
          if (distancia() == 1) {
            // Podemos atrapar a Tapia en un movimiento
            acercar_horizontal_Juan();
            ultimo_movimiento = mueve(x_juan, y_juan);
          } else {
            // Tapia intentara cambiar la paridad
            actualizar_Juan(ARRIBA);
            ultimo_movimiento = mueve(x_juan, y_juan);
          }
        } else {
          // x_juan < x_tapia
          if (std::abs(y_juan - y_tapia) <= std::abs(x_juan - x_tapia)) {
            // Podemos atrapar a Tapia
            actualizar_Juan(ABAJO);
            ultimo_movimiento = mueve(x_juan, y_juan);
          } else {
            // Tapia intentara cambiar la paridad
            if (std::abs(y_juan - y_tapia) == std::abs(x_juan - x_tapia) + 1) {
              // Si lo alcanzamos a acorralar
              acercar_horizontal_Juan();
              ultimo_movimiento = mueve(x_juan, y_juan);
            } else {
              // Anticipar movimientos de Tapia
              actualizar_Juan(ARRIBA);
              ultimo_movimiento = mueve(x_juan, y_juan);
            }
          }
        }
      }
    }
    actualizar_Tapia(ultimo_movimiento);
  }
}
