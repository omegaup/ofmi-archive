#include "numeroespecial.h"

long long cntNoDivisible(long long N, long long k) { return N - N / k; }

long long numeroEspecial(long long n, long long m, long long k) {
  long long x = m, y = n * 2LL + m + k;
  long long mid;
  while (x < y) {
    mid = (x + y) / 2LL;
    long long numNonDivisibles =
        cntNoDivisible(mid, k) - cntNoDivisible(m - 1LL, k);
    if (numNonDivisibles < n) {
      x = mid + 1LL;
    } else {
      y = mid;
    }
  }
  return x;
}
