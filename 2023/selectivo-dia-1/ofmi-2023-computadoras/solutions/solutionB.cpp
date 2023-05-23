#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include "computadoras.h"

void computadoras(int n, int p, int m, int P[], int M[]) {
  // agregamos todas las computadoras a una estructura para ordenarlas
  std::vector<std::pair<std::pair<int, int>, int>> c;
  c.push_back(
      std::pair<std::pair<int, int>, int>(std::pair<int, int>(p, m), 0));
  for (int i = 0; i < n; ++i)
    if (P[i] >= p && M[i] >= m)
      c.push_back(std::pair<std::pair<int, int>, int>(
          std::pair<int, int>(P[i], M[i]), i + 1));

  sort(c.begin(), c.end());

  // estructuras para almacenar la máxima longitud de la subsecuencia que
  // termina en el índice i y la lista de índices que la conforma
  std::vector<int> ln(c.size());
  std::vector<std::list<int>> idx(c.size());

  int gmln = 1,
      gmidx = 0;  // máxima longitud global y el índice en el que termina

  // dp: subsecuencia incremental máxima sobre las dos dimensiones
  ln[0] = 1;
  idx[0] = {0};
  for (int i = 1; i < c.size(); ++i) {
    int mln = 1;
    std::list<int> midx = {i};
    for (int j = 0; j < i; ++j) {
      if (c[j].first.first < c[i].first.first &&
          c[j].first.second < c[i].first.second && ln[j] + 1 > mln) {
        mln = ln[j] + 1;
        midx = idx[j];
        midx.push_back(i);
      }
    }
    ln[i] = mln;
    idx[i] = midx;
    if (mln > gmln) {
      gmln = mln;
      gmidx = i;
    }
  }

  // presentar la subsecuencia con máxima longitud global
  for (auto d : idx[gmidx]) presenta(c[d].second);
}
