#include "recorriendo.h"

int distancia = 0;
int giros = 0;
int direccion = 1;

void adelante(int x) {
  distancia += x;
  if (direccion == -1) {
    giros++;
    direccion = 1;
  }
}

void atras(int y) {
  distancia -= y;
  if (direccion == 1) {
    giros++;
    direccion = -1;
  }
}

int avanzado() { return distancia; }

int vueltas() { return giros; }
