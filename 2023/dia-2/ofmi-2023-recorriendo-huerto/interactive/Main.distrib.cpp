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
    std::cin >> instruction;

    switch (instruction) {
      case INS_ADELANTE: {
        std::cin >> param;
        std::cerr << "Llamando adelante(" << param << ")" << std::endl;

        adelante(param);

        break;
      }
      case INS_ATRAS: {
        std::cin >> param;
        std::cerr << "Llamando atras(" << param << ")" << std::endl;

        atras(param);

        posicion -= param;
        if (direccion == 1) {
          giros++;
          direccion = -1;
        }

        break;
      }
      case INS_AVANZANDO: {
        std::cerr << "Llamando avanzado()" << std::endl;
        int a = avanzado();
        std::cerr << "Resultado " << a << std::endl;

        break;
      }
      case INS_VUELTAS: {
        std::cerr << "Llamando vueltas()" << std::endl;
        int v = vueltas();
        std::cerr << "Resultado " << v << std::endl;

        break;
      }
      default: {
        std::cerr << "Instruccion invalida " << instruction << std::endl;
        return 1;
      }
    }
  }

  return 0;
}