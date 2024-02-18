#include <algorithm>
#include <iostream>

int n;
const int MAX_N = 1e5;

struct Punto {
  int p;
  int idx;
};

struct Rango {
  std::pair<int, int> r;
  int idx;
};

bool comparaPuntos(Punto A, Punto B) { return A.p < B.p; }

bool comparaRangos(Rango A, Rango B) { return A.r < B.r; }

Punto puntos[MAX_N];  // Arreglo para guardar los puntos
Rango rangos[MAX_N];  // Arreglo para guardar los rangos
int res[MAX_N];       // Arreglo para la respuesta final

int main() {
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> puntos[i].p;
    puntos[i].idx = i;
  }
  for (int i = 0; i < n; i++) {
    // En orden inverso para ordenarlos por fin
    std::cin >> rangos[i].r.second >> rangos[i].r.first;
    rangos[i].idx = i;
  }

  // Ordenamos los puntos
  std::sort(puntos, puntos + n, comparaPuntos);

  // Ordenamos los rangos por fin
  std::sort(rangos, rangos + n, comparaRangos);

  // Intentamos emparejar el rango i con el punto i en los arreglos ordenados
  bool posible = true;
  for (int i = 0; i < n; i++) {
    if (rangos[i].r.first >= puntos[i].p and
        puntos[i].p >= rangos[i].r.second) {
      res[rangos[i].idx] = puntos[i].idx;
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
