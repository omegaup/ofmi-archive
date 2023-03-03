#include <iostream>
#include <string>

#include "nicolas.h"

const int NUM_SUB = 4;
const int MAX_X = 1000;
const int LOG_L = 10;
int subtask;
int velocidad, longitud;
int tiempo;
int cola, cabeza;

int getSubtask(const std::string& caseName) {
  for (int sub = 1; sub <= NUM_SUB; ++sub) {
    if (caseName.find("sub" + std::to_string(sub)) != std::string::npos) {
      return sub;
    }
  }
  return -1;
}

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
  return ans;
}

bool called_reporta = false;
void reporta(int X, int L) {
  if (called_reporta) {
    return;
  }
  called_reporta = true;

  if (X != velocidad || L != longitud) {
    std::cout << 0 << std::endl;
    return;
  }
  if (subtask != 4) {
    std::cout << 1 << std::endl;
    return;
  }

  std::cerr << "Llamadas a foto: " << tiempo << std::endl;

  int cota20 = MAX_X + 2 * LOG_L;
  int cota50 = MAX_X + LOG_L;
  int cota100 = MAX_X;
  if (tiempo > cota20) {
    std::cout << 0 << std::endl;
    return;
  }
  if (tiempo > cota50) {
    std::cout << 0.2 << std::endl;
    return;
  }
  if (tiempo > cota100) {
    std::cout << 0.5 << std::endl;
    return;
  }

  std::cout << 1 << std::endl;
}

int main(int argc, char* argv[]) {
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  subtask = getSubtask(caseName);
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
