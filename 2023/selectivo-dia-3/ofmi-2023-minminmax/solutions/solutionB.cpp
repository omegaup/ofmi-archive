#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <utility>

#include "minminmax.h"

int minMinMax(int n, int m, int A[]) {
  int mi, ma, fi, la, tmp;
  for (int i = 0; i < n; ++i) {
    tmp = A[i];
    if (i == 0) fi = tmp;
    if (i == 0 || tmp < mi) mi = tmp;
    if (i == 0 || tmp > ma) ma = tmp;
    if (i == n - 1) la = tmp;
  }

  if (m == 1) return ma;
  if (m == 2) return std::min(fi, la);
  return mi;
}
