#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <utility>
#include <vector>

#include "maldoso.h"

std::pair<int64_t, int64_t> solve(int64_t i, int64_t j) {
  int64_t a1ma0, ma02;
  a1ma0 = pregunta(j, i);
  ma02 = pregunta(i, j);
  int64_t a0 = (-ma02) / 2;

  return std::pair<int64_t, int64_t>(a0, a1ma0 + a0);
}

std::pair<int64_t, int64_t> solve1(int64_t a0, int64_t i, int64_t j) {
  int64_t a1ma0;
  a1ma0 = pregunta(j, i);

  return std::pair<int64_t, int64_t>(a0, a1ma0 + (-a0) * 2);
}

void maldoso(int n) {
  int A[n];

  for (int i = 0; i < n / 2; ++i) {
    std::pair<int64_t, int64_t> p = solve(2 * i, 2 * i + 1);
    A[2 * i] = p.first;
    A[2 * i + 1] = p.second;
  }
  if (n % 2) {
    std::pair<int64_t, int64_t> p = solve1(A[n - 3], n - 2, n - 1);
    A[n - 1] = p.second;
  }

  respuesta(n, A);
}
