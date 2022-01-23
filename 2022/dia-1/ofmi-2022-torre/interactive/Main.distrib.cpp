#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#include <iostream>

#include "torre.h"

int n, m;
int i_juan, j_juan;    // Juanito
int i_tapia, j_tapia;  // Tapia

int movimientos;
bool tapiaAtrapado;
bool movimientoInvalido;
bool llamadaInvalida;

const int ARRIBA = 1;
const int ABAJO = 2;
const int DERECHA = 3;
const int IZQUIERDA = 4;

bool esMovimientoValidoJuanito(int i, int j) {
  if (i < 0 || j < 0 || i > n || j > m) {
    return false;
  }
  if (i == 0 && j == 0) {
    return i_juan == 1;
  }
  if (i == 0 || j == 0) {
    return false;
  }
  if (i_juan == 0) {
    return i == 1;
  }
  return abs(i_juan - i) + abs(j_juan - j) == 1;
}

bool esMovimientoValidoTapia(int i, int j) {
  if (i < 0 || j < 0 || i > n || j > m) {
    return false;
  }
  if (i == 0 && j > 0) {
    return false;
  }
  if (i > 0 && j == 0) {
    return false;
  }
  return i_juan != i || j_juan != j;
}

// Se moverá Tapia aleatoriamente
// NOTA: Tapia no se moverá con la misma estrategia en los casos de prueba
int mueveTapia() {
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
      if (mov == ARRIBA && esMovimientoValidoTapia(i_tapia - 1, j_tapia)) {
        i_tapia--;
        if (i_tapia == 0) {
          j_tapia = 0;
        }
        return ARRIBA;
      }
      if (mov == ABAJO && esMovimientoValidoTapia(i_tapia + 1, j_tapia)) {
        i_tapia++;
        return ABAJO;
      }
      if (mov == DERECHA && esMovimientoValidoTapia(i_tapia, j_tapia + 1)) {
        j_tapia++;
        return DERECHA;
      }
      if (mov == IZQUIERDA && esMovimientoValidoTapia(i_tapia, j_tapia - 1)) {
        j_tapia--;
        return IZQUIERDA;
      }
    }
  }
}

int mueve(int i, int j) {
  if (movimientoInvalido || tapiaAtrapado || llamadaInvalida) {
    std::cerr
        << "ERROR: Realizaste una llamada invalida. "
        << "Si ya has atrapado a Tapia no debes volver a llamar 'mueve'\n";
    llamadaInvalida = true;
    return -1;
  }
  movimientos++;
  if (!esMovimientoValidoJuanito(i, j)) {
    std::cerr << "ERROR: Moviste a Juanito a una posicion invalida\n";
    movimientoInvalido = true;
    return -1;
  }
  i_juan = i;
  j_juan = j;
  if (i_juan == i_tapia && j_juan == j_tapia) {
    // Has atrapado a Tapia
    tapiaAtrapado = true;
    std::cout << "mueve(" << i << ", " << j << ")  -> " << 0 << std::endl;
    return 0;
  }
  // Hora de mover a Tapia
  int mov = mueveTapia();
  std::cout << "mueve(" << i << ", " << j << ")  -> " << mov << std::endl;
  std::cout << "Ahora Tapia se encuentra en (" << i_tapia << ", " << j_tapia
            << ")\n";
  return mov;
}

int main() {
  std::cin >> n >> m;
  std::cin >> i_juan >> j_juan;
  std::cin >> i_tapia >> j_tapia;

  /* initialize random seed: special for the case*/
  srand(n + m + i_juan + j_juan + i_tapia + j_tapia);

  std::cout << "Llamando a función juega(" << n << ", " << m << ", " << i_juan
            << ", " << j_juan << ", " << i_tapia << ", " << j_tapia << ")\n";
  juega(n, m, i_juan, j_juan, i_tapia, j_tapia);

  if (movimientoInvalido || llamadaInvalida) {
    std::cout
        << "Respuesta incorrecta. Hubo un error en tus llamadas a 'mueve'\n";
    return 0;
  }
  if (!tapiaAtrapado) {
    std::cout << "Respuesta incorrecta. No has atrapado a Tapia\n";
    return 0;
  }
  std::cout << "¡Respuesta correcta! Atrapaste a Tapia y moviste a Juanito "
            << movimientos << " veces.\n";
  return 0;
}
