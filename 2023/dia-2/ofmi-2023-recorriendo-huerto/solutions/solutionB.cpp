#include "recorriendo.h"

int curr_pos;
int v;
int last;

void adelante(int x) {
  if (last == -1) {
    v++;
  }
  last = 0;
  curr_pos += x;
}

void atras(int y) {
  if (last == 0) {
    v++;
  }
  last = -1;
  curr_pos -= y;
}

int avanzado() { return curr_pos; }

int vueltas() { return v; }
