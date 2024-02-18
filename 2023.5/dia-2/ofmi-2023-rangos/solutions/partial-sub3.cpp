#include <algorithm>
#include <iostream>

int n;
const int MAX_N = 1e5;

struct Medicion {
  int p;
  int idx;
};

struct Rango {
  std::pair<int, int> r;
  int idx;
};

bool comparaMediciones(Medicion A, Medicion B) { return A.p < B.p; }

bool comparaRangos(Rango A, Rango B) { return A.r < B.r; }

Medicion mediciones[MAX_N];  // Arreglo para guardar las mediciones
Rango rangos[MAX_N];         // Arreglo para guardar los rangos
int res[MAX_N];              // Arreglo para la respuesta final

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> mediciones[i].p;
    mediciones[i].idx = i;
  }
  for (int i = 0; i < n; i++) {
    std::cin >> rangos[i].r.first >> rangos[i].r.second;
    rangos[i].idx = i;
  }

  // Ordenamos las mediciones
  std::sort(mediciones, mediciones + n, comparaMediciones);

  // Ordenamos los rangos
  std::sort(rangos, rangos + n, comparaRangos);

  // Intentamos emparejar el rango i con la medición i en los arreglos ordenados
  bool posible = true;
  for (int i = 0; i < n; i++) {
    if (rangos[i].r.first <= mediciones[i].p and
        mediciones[i].p <= rangos[i].r.second) {
      res[rangos[i].idx] = mediciones[i].idx;
    } else {
      posible = false;
      break;
    }
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