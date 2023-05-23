#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>

#include "compresion.h"

int compresion(int n, int m, int A[]) {
  std::map<int, int> c;
  for (int i = 0; i < n; ++i) ++c[A[i]];

  // No es necesario aplastar
  if (c.size() <= m) return 0;

  // Calcular cantidad de numeros con los primeros m distintos
  int rc = 0;
  auto jt = c.begin();
  for (int i = 0; i < m - 1; ++i, ++jt) rc += jt->second;

  int mc = n, pv = 0, a, b;
  for (auto it = c.begin(); jt != c.end(); ++it, ++jt) {
    // Contando cantidad de numeros en el rango [it, jt]
    rc += jt->second - pv;
    if (n - rc < mc) {
      // La cantidad de numeros a eliminar es menor que la respuesta anterior
      mc = n - rc;
      a = it->first;
      b = jt->first;
    }

    pv = it->second;
  }

  aplasta(a, b);

  return mc;
}
