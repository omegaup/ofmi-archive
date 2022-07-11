#include <algorithm>
#include <vector>

#include "frekuencias.h"

int frekuencia(int N, char S[]) {
  int respuesta = 0;
  int menor, mayor;
  std::vector<int> cubetas(150, 0);

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      for (int k = i; k <= j; k++) cubetas[S[k]]++;
      menor = 10000;
      mayor = 0;
      for (int k = 'a'; k <= 'z'; k++) {
        if (cubetas[k] > 0) menor = std::min(menor, cubetas[k]);
        mayor = std::max(mayor, cubetas[k]);
        cubetas[k] = 0;
      }
      respuesta = std::max(respuesta, mayor - menor);
    }
  }
  return respuesta;
}
