// Subtarea 1: q <= 2000
//
// Al ser pocas expediciones, por cada expedicion nueva podemos
// recorrer las anteriores y filtrar las que colisionen con la nueva.
#include <iostream>

const int MaxN = 2e5 + 10;

int num_expediciones;
int expedicion_hormiguero[MaxN];
int expedicion_platillo[MaxN];

int agregar_expedicion(int hormigas, int platillo) {
  int num_expediciones_activas = 0;
  int num_expediciones_retiradas = 0;
  for (int i = 0; i < num_expediciones; ++i) {
    if (expedicion_hormiguero[i] == hormigas) {
      // La expedicion con [hormigas] la retiramos sin costo
      continue;
    }
    if (expedicion_hormiguero[i] < hormigas) {
      // Si el hormiguero esta antes, el platillo debe estar antes o ser
      // [platillo]
      if (expedicion_platillo[i] <= platillo) {
        expedicion_hormiguero[num_expediciones_activas] =
            expedicion_hormiguero[i];
        expedicion_platillo[num_expediciones_activas] = expedicion_platillo[i];
        ++num_expediciones_activas;
      } else {
        ++num_expediciones_retiradas;
      }
    } else {
      // Si el hormiguero esta despues, el platillo debe estar despues o ser
      // [platillo]
      if (expedicion_platillo[i] >= platillo) {
        expedicion_hormiguero[num_expediciones_activas] =
            expedicion_hormiguero[i];
        expedicion_platillo[num_expediciones_activas] = expedicion_platillo[i];
        ++num_expediciones_activas;
      } else {
        ++num_expediciones_retiradas;
      }
    }
  }

  // Agregamos la nueva expedicion
  expedicion_hormiguero[num_expediciones_activas] = hormigas;
  expedicion_platillo[num_expediciones_activas] = platillo;
  num_expediciones = num_expediciones_activas + 1;

  // Regresar las expediciones que retiramos
  return num_expediciones_retiradas;
}

int main() {
  int N, M, Q;
  std::cin >> N >> M >> Q;
  for (int i = 0; i < Q; ++i) {
    int hormigas, platillo;
    std::cin >> hormigas >> platillo;
    int filas_retiradas = agregar_expedicion(hormigas, platillo);
    std::cout << filas_retiradas << "\n";
  }
}
