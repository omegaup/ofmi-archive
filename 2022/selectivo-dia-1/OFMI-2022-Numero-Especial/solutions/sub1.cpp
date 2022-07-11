#include "numeroespecial.h"

long long numeroEspecial(long long n, long long m, long long k) {
  long long x = 0;
  while (x < n) {
    if (m % k != 0) {
      x++;
      if (x == n) return m;
    }
    m++;
  }
}
