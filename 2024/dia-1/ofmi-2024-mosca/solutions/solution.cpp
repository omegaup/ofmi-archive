#include <iostream>
#include <vector>

int main() {
  // Leemos n y m
  int n, m;
  std::cin >> n >> m;

  // Leemos el arreglo P de m enteros
  std::vector<int> P(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> P[i];
  }

  // Leemos q
  int q;
  std::cin >> q;
  // Leemos y vamos respondiendo las preguntas de tal forma que
  // [idxActual] sea el grupo que Andrea está asignando.
  int idxActual = 0;
  int yaAsignadas = 0;

  for (int j = 0; j < q; ++j) {
    int ai;
    std::cin >> ai;
    // Determinamos en qué grupo (definido por P) cae ai
    while (yaAsignadas + P[idxActual] < ai) {
      // Si puedo asignar todas las del grupo actual [idxActual]
      // entonces la amiga ai no está en ese grupo.
      // Por lo que podemos asignarlas y pasarnos al siguiente.
      yaAsignadas += P[idxActual];
      idxActual++;
    }
    // Sabemos que la amiga ai entonces está en el
    // grupo de P[idxActual], por lo que será mosca si
    // idxActual es par, o abeja si es impar
    if ((idxActual % 2) == 0) {
      std::cout << "Mosca\n";
    } else {
      std::cout << "Abeja\n";
    }
  }

  return 0;
}
