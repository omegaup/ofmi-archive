#include <iostream>

#include "numeroespecial.h"

long long getNonDivisibles(long long N, long long k) { return N - N / k; }

long long getNumeroEspecial(long long n, long long m, long long k) {
  long long x = m, y = n * 2LL + m + k;
  long long mid;
  while (x < y) {
    mid = (x + y) / 2LL;
    long long numNonDivisibles =
        getNonDivisibles(mid, k) - getNonDivisibles(m - 1LL, k);
    if (numNonDivisibles < n) {
      x = mid + 1LL;
    } else {
      y = mid;
    }
  }
  return x;
}

int main() {
  long long n, m, k;
  std::cin >> n >> m >> k;

  long long contestNumber = numeroEspecial(n, m, k);

  if (contestNumber == getNumeroEspecial(n, m, k)) {
    printf("1.00\n");
  } else {
    printf("0.00\n");
  }
  return 0;
}
