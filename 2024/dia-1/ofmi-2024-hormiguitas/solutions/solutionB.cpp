#include <algorithm>
#include <iostream>
#include <map>
#include <set>

const int MaxN = 1e6 + 10;
int objetivo_actual_del_hormiguero[MaxN];

int N, M, Q;
std::set<int> hormigas_en_expedicion;

int agregar_expedicion(int hormigas, int platillo) {
  // Para agregar una nueva expedicion, tenemos que checar que el hormiguero
  // no colisiona con expediciones de sus vecinos, tanto para hormigueros
  // menores como mayores a [hormigas].
  //
  // Buscamos estos hormigueros en [hormigas_en_expedicion] con lower_bound.

  // Hacemos que se regresen primero las [hormigas] si es que fueron de
  // expedicion.
  hormigas_en_expedicion.erase(hormigas);

  int expediciones_retiradas = 0;
  // Expediciones de hormigas mayores a [hormigas].
  while (!hormigas_en_expedicion.empty()) {
    auto hormigas_vecinas_mayores_iter =
        hormigas_en_expedicion.lower_bound(hormigas);
    if (hormigas_vecinas_mayores_iter == hormigas_en_expedicion.end()) {
      // No hay vecinas mayores de [hormigas].
      break;
    }
    int hormigas_vecinas_mayores = *hormigas_vecinas_mayores_iter;
    if (objetivo_actual_del_hormiguero[hormigas_vecinas_mayores] < platillo) {
      // Hay conflicto con las hormigas vecinas, estas se retiran.
      hormigas_en_expedicion.erase(hormigas_vecinas_mayores);
      ++expediciones_retiradas;
    } else {
      // Todo bien con las vecinas.
      break;
    }
  }

  // Expediciones de hormigas menores a [hormigas].
  while (!hormigas_en_expedicion.empty()) {
    auto hormigas_vecinas_menores_iter =
        hormigas_en_expedicion.lower_bound(hormigas);
    if (hormigas_vecinas_menores_iter == hormigas_en_expedicion.begin()) {
      // No hay vecinas menores de [hormigas].
      break;
    }
    auto hormigas_vecinas_menores = *(--hormigas_vecinas_menores_iter);
    if (platillo < objetivo_actual_del_hormiguero[hormigas_vecinas_menores]) {
      // Hay conflicto con las hormigas vecinas, estas se retiran.
      hormigas_en_expedicion.erase(hormigas_vecinas_menores);
      ++expediciones_retiradas;
    } else {
      // Todo bien con las vecinas.
      break;
    }
  }

  // Agregamos la nueva expedicion.
  hormigas_en_expedicion.insert(hormigas);
  objetivo_actual_del_hormiguero[hormigas] = platillo;

  // Regresamos la cantidad de expediciones removidas.
  return expediciones_retiradas;
}

int main() {
  std::cin >> N >> M >> Q;
  for (int i = 0; i < Q; ++i) {
    int hormigas, platillo;
    std::cin >> hormigas >> platillo;
    int expediciones_eliminadas = agregar_expedicion(hormigas, platillo);
    std::cout << expediciones_eliminadas << "\n";
  }
  return 0;
}
