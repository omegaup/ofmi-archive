#include "recorriendo.h"

int curr_pos;
int v;

void adelante(int x) { curr_pos += x; }

void atras(int y) {
  curr_pos -= y;
  v = 1;
}

int avanzado() { return curr_pos; }

int vueltas() { return v; }
