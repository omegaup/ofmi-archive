#include <iostream>

int main() {
  int n;
  std::string comandos;
  std::cin >> n >> comandos;

  int desplazamiento_izquierda = 0;
  int desplazamiento_derecha = 0;
  int desplazamiento_arriba = 0;
  int desplazamiento_abajo = 0;

  for (int i = 0; i < n; i++) {
    if (comandos[i] == '<') {
      desplazamiento_izquierda++;
    }

    if (comandos[i] == '>') {
      desplazamiento_derecha++;
    }

    if (comandos[i] == '^') {
      desplazamiento_arriba++;
    }

    if (comandos[i] == 'v') {
      desplazamiento_abajo++;
    }
  }

  int latitud = desplazamiento_arriba - desplazamiento_abajo;
  int longitud = desplazamiento_derecha - desplazamiento_izquierda;

  std::cout << latitud << ' ' << longitud << '\n';
}
