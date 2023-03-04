#include "recorriendo.h"

int curr_pos;

void adelante(int x) { curr_pos += x; }

void atras(int y) { return; }

int avanzado() { return curr_pos; }

int vueltas() { return 0; }
