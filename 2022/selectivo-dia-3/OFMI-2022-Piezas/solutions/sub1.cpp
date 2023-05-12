#include <vector>

#include "piezasdefomi.h"

int palabraFavorita(int n, char s[], int m, char piezas[]) {
  std::vector<int> cubetaAndrea(26, 0);
  for (int i = 0; i < n; ++i) {
    ++cubetaAndrea[s[i] - 'a'];
  }
  std::vector<int> cubetaPiezas(26, 0);
  for (int i = 0; i < m; ++i) {
    ++cubetaPiezas[piezas[i] - 'a'];
  }

  int maximaCantidad = 0;
  bool almenosUna = false;
  for (int i = 0; i < 26; ++i) {
    if (cubetaAndrea[i]) {
      int cntPiezas = cubetaPiezas[i] / cubetaAndrea[i];
      if (!almenosUna || cntPiezas < maximaCantidad) {
        maximaCantidad = cntPiezas;
        almenosUna = true;
      }
    }
  }

  return maximaCantidad;
}
