#include <iostream>

#include "nicolas.h"

int velocidad, longitud;
int tiempo;
int cola, cabeza;

bool foto(int y) {
  // Hacemos pasar un segundo
  tiempo++;
  cola += velocidad;
  cabeza += velocidad;

  bool ans;
  if (cola <= y && y <= cabeza) {
    // Si está en el intervalo, lo vemos
    ans = true;
  } else {
    // Si no está en el intervalo, no lo vemos
    ans = false;
  }
  std::cerr << "Llamaste a la funcion foto(" << y << ")"
            << " -> " << ans << std::endl;
  return ans;
}

void reporta(int X, int L) {
  std::cerr << "Llamaste a la funcion reporta(" << X << ", " << L << ")"
            << std::endl;
  std::cerr << "Tiempo: " << tiempo << std::endl;
  if (X != velocidad || L != longitud) {
    std::cerr << "Los valores que devolviste no son correctos" << std::endl;
    std::cerr << "Los valores correctos son: X=" << velocidad << " y L=" << L
              << std::endl;
    std::cout << 0 << std::endl;
  } else {
    std::cerr << "Los valores que devolviste son correctos! :D" << std::endl;
    std::cout << 1 << std::endl;
  }
}

int main() {
  // Leemos los valores desconocidos X y L
  std::cin >> velocidad >> longitud;
  // Inicializamos valores de la posición de nicolás en el tiempo 0
  tiempo = 0;
  cola = 0;
  cabeza = longitud - 1;
  // Llamamos a la función de la participante
  nicolas();
  return 0;
}
