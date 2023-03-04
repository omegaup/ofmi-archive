#include <iostream>

#include "recorriendo.h"

const int INS_ADELANTE = 1;
const int INS_ATRAS = 2;
const int INS_AVANZANDO = 3;
const int INS_VUELTAS = 4;

int posicion = 0;
int giros = 0;
int direccion = 1;

int main() {
  int n;

  std::cin >> n;

  for (int i = 0; i < n; i++) {
    int instruction;
    int param;
    int r;
    std::cin >> instruction;

    switch (instruction) {
      case INS_ADELANTE: {
        std::cin >> param;
        adelante(param);

        posicion += param;
        if (direccion == -1) {
          giros++;
          direccion = 1;
        }

        break;
      }
      case INS_ATRAS: {
        std::cin >> param;
        atras(param);

        posicion -= param;
        if (direccion == 1) {
          giros++;
          direccion = -1;
        }

        break;
      }
      case INS_AVANZANDO: {
        r = avanzado();

        if (posicion != r) {
          std::cout << "0" << std::endl;
          return 0;
        }
        break;
      }
      case INS_VUELTAS: {
        r = vueltas();

        if (giros != r) {
          std::cout << "0" << std::endl;
          return 0;
        }
        break;
      }
      default: {
        std::cerr << "Instruccion invalida " << instruction << std::endl;
        return 1;
      }
    }
  }

  std::cout << "1" << std::endl;

  return 0;
}