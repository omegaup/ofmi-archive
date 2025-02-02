// Subtarea 3: Solo tenemos una columna de tulipanes.
//
// Esta es la misma solucion que el archivo [sub3.cpp]. La
// diferencia es que en este codigo no estamos contemplando que
// los tulipanes pueden ser representados con numeros de hasta
// un millon, por lo que hacer un arreglo de mil posiciones no
// sera suficiente y nos marcaria error de ejecucion en omegaUp.
#include <iostream>

const int MaxN = 1010;
int conteo[MaxN];
int primera_aparicion[MaxN];
int ultima_aparicion[MaxN];

int main() {
  int n, m;
  std::cin >> n >> m;

  for (int j = 0; j < m; ++j) {
    int tulipan;
    std::cin >> tulipan;
    if (conteo[tulipan] == 0) {
      primera_aparicion[tulipan] = j;
    }
    ultima_aparicion[tulipan] = j;
    ++conteo[tulipan];
  }

  int max_repeticiones = 0;
  int respuesta = 0;
  for (int tulipan = 0; tulipan < m; ++tulipan) {
    if (max_repeticiones <= conteo[tulipan]) {
      int flores = ultima_aparicion[tulipan] - primera_aparicion[tulipan] + 1;
      int desperdicio = flores - conteo[tulipan];
      if (max_repeticiones < conteo[tulipan] || desperdicio < respuesta) {
        max_repeticiones = conteo[tulipan];
        respuesta = desperdicio;
      }
    }
  }
  std::cout << respuesta << "\n";
  return 0;
}
