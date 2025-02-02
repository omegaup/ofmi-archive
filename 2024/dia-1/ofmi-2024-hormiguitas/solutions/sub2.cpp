// Subtarea 2: u_i <= u_j
//
// Las nuevas expediciones siempre seran de hormigueros cada vez
// mas a la derecha, por lo que solo tenemos que checar cuales
// expediciones tienen un platillo mas a la derecha que la nueva
// expedicion.
#include <iostream>

const int MaxN = 2e5 + 10;
int num_expediciones_actuales;
int expedicion_hormiguero[MaxN];
int expedicion_platillo[MaxN];

int agregar_expedicion(int hormigas, int platillo) {
  // Checamos si la ultima expedicion fue hecha por [hormigas]. En caso
  // de serlo, solo la quitamos.
  if (num_expediciones_actuales > 0) {
    int hormiguero_de_ultima_expedicion =
        expedicion_hormiguero[num_expediciones_actuales - 1];
    if (hormiguero_de_ultima_expedicion == hormigas) {
      --num_expediciones_actuales;
    }
  }

  // Checamos cuales expediciones tienen platillo mas grande que
  // la nueva expedicion
  int num_expediciones_retiradas = 0;
  while (num_expediciones_actuales > 0) {
    int platillo_de_ultima_expedicion =
        expedicion_platillo[num_expediciones_actuales - 1];
    if (platillo_de_ultima_expedicion > platillo) {
      --num_expediciones_actuales;
      ++num_expediciones_retiradas;
    } else {
      break;
    }
  }

  // Agregamos la nueva expedicion
  expedicion_hormiguero[num_expediciones_actuales] = hormigas;
  expedicion_platillo[num_expediciones_actuales] = platillo;
  ++num_expediciones_actuales;

  // Regresamos la cantidad de expediciones retiradas
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
