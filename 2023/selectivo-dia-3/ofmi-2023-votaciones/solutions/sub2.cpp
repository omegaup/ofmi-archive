#include <iostream>
#include <vector>

#include "votaciones.h"

int visited[(1 << 20) + 2];

int toId(int n, int A[]) {
  int id = 0;
  for (int i = 0; i < n; ++i) {
    id = id * 2 + A[i];
  }
  return id;
}

void votacion(int n, int m, int A[]) {
  int prev[n];
  int prevId;
  int curr[n];
  int currId;
  for (int i = 0; i < n; ++i) {
    curr[i] = A[i];
  }
  int t = 1;
  currId = toId(n, curr);
  visited[toId(n, curr)] = t;
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < n; ++i) {
      prev[i] = curr[i];
    }
    prevId = currId;
    for (int i = 0; i < n; ++i) {
      int neighbor = (i + 1) % n;
      if (prev[neighbor] == 1) {
        curr[i] = prev[i] ^ 1;
      } else {
        curr[i] = prev[i];
      }
    }
    t++;
    currId = toId(n, curr);
    if (visited[currId]) {
      // Found a cycle
      int cycleLength = t - visited[currId];
      int remaining = (m - k - 1) % cycleLength;
      k = m - remaining - 1;
    }
    visited[currId] = t;
  }
  resultados(n, curr);
}
