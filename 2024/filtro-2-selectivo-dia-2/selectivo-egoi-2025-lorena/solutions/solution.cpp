#include "ruleta.h"

int encuentra(int x, int n) {
  int A0 = pregunta(0);
  if (A0 == x) return 0;

  int l = 1, r = n;
  while (l < r) {
    int m = (l + r) / 2;

    int Am = pregunta(m);
    if (Am == x) return m;

    if ((A0 < Am && Am < x) || (x < A0 && A0 < Am) || (Am < x && x < A0))
      l = m + 1;
    else
      r = m;
  }
  return -1;
}
