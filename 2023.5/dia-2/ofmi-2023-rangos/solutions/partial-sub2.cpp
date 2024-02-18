#include <algorithm>
#include <iostream>

int n;
const int MAX_N = 1e5;

int mediciones[MAX_N];              // Arreglo para guardar las mediciones
std::pair<int, int> rangos[MAX_N];  // Arreglo para guardar los rangos
int res[MAX_N];                     // Arreglo para la respuesta final
bool usado[MAX_N];  // Arreglo para registrar que rangos ya fueron asignados a
                    // alguna participante

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> mediciones[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> rangos[i].first >> rangos[i].second;
  }

  // Recorremos el arreglo ordenado de mediciones
  bool posible = true;
  for (int i = 0; i < n; i++) {
    // Entre los rangos que aún no se han usado, buscamos uno que contenga a
    // la medición

    int rangoAsignado = -1;
    for (int j = 0; j < n; j++) {
      // Si el rango ya está asignado a alguna otra medición, no lo consideramos
      if (usado[j]) {
        continue;
      }

      // Verificamos que el rango contenga a la medición
      if (rangos[j].first <= mediciones[i] and
          mediciones[i] <= rangos[j].second) {
        rangoAsignado = j;
        break;
      }
    }

    // Si no encontramos ningún rango que contenga a la medición, no hay
    // solución
    if (rangoAsignado == -1) {
      posible = false;
      break;
    }

    res[rangoAsignado] = i;
    usado[rangoAsignado] = true;
  }

  if (posible) {
    // Imprimimos la asignación obtenida
    for (int i = 0; i < n; i++) {
      std::cout << res[i] << " ";
    }
    std::cout << "\n";
  } else {
    std::cout << "-1\n";
  }

  return 0;
}