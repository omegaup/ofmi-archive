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

int distancia(int x, int y, int a, int b) {
  if (x == 0 || a == 0) {
    // Distancia al techo
    return x + a;
  }
  return std::abs(x - a) + std::abs(y - b);
}

bool misma_paridad() {
  return distancia(x_juan, y_juan, x_tapia, y_tapia) % 2 == 0;
}

void techo_juan() {
  // A Juan le conviene saltar a la columna de Tapia
  actualizar_Juan(y_tapia);
  if (x_tapia == 1) {
    // Atrapamos a Tapia
    return;
  }
  if (!misma_paridad()) {
    if (y_tapia != M) {
      actualizar_Juan(DERECHA);
    } else if (y_tapia != 1) {
      actualizar_Juan(IZQUIERDA);
    }
  }
}

void acercar_Juan() {
  // Acercamos a Juan a la posicion de Tapia
  if (distancia(x_juan, y_juan, x_tapia, y_tapia) == 1) {
    // Naranja
    // Mover a posicion de Tapia
    x_juan = x_tapia;
    y_juan = y_tapia;
    return;
  } else if (std::abs(y_juan - y_tapia) > x_tapia - x_juan + 1) {
    // Amarilla
    if (y_juan < y_tapia) {
      actualizar_Juan(DERECHA);
    } else {
      actualizar_Juan(IZQUIERDA);
    }
  } else {
    // Morada
    actualizar_Juan(ABAJO);
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
      if (misma_paridad() ||
          std::abs(y_juan - y_tapia) > x_tapia - x_juan + 1) {
        // Hay que cambiar la paridad
        // Juan todavia no esta en el techo
        actualizar_Juan(ARRIBA);
        ultimo_movimiento = mueve(x_juan, y_juan);
      } else {
        acercar_Juan();
        ultimo_movimiento = mueve(x_juan, y_juan);
      }
    }
    actualizar_Tapia(ultimo_movimiento);
  }
}
