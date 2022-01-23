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
  return std::min(std::abs(x - a) + std::abs(y - b), x + a);
}

void techo_juan() {
  // A Juan le conviene saltar a la columna de Tapia
  actualizar_Juan(y_tapia);
}

void acercar_Juan() {
  // Acercamos a Juan a la posicion de Tapia
  int dist_cercana = 2 * (N + M);
  int mov_cercano = 0;

  for (int mov = 4; mov >= 1; --mov) {
    int x = x_juan + movs[mov][0];
    int y = y_juan + movs[mov][1];
    if (x == 0) {
      y = 0;
    }
    if (x < 0 || y < 0 || x == N + 1 || y == M + 1) {
      continue;
    }
    int dist = distancia(x, y, x_tapia, y_tapia);
    if (dist < dist_cercana) {
      dist_cercana = dist;
      mov_cercano = mov;
    }
  }
  actualizar_Juan(mov_cercano);
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
      acercar_Juan();
      ultimo_movimiento = mueve(x_juan, y_juan);
    }
    actualizar_Tapia(ultimo_movimiento);
  }
}
