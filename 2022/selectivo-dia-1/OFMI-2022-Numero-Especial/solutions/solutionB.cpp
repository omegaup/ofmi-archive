#include "numeroespecial.h"

typedef long long int lld;

/*
numeroEspecial returns the n-th not divisible by k
starting at m
*/
long long numeroEspecial(long long n, long long m, long long k) {
  long long ini = m, fin = 1e18;
  long long y = (m - 1LL);
  while (ini < fin) {
    long long med = (ini + fin) / 2LL;
    long long x = med - (med / k) - (m - 1LL) + ((m - 1LL) / k);
    if (x < n) {
      ini = med + 1LL;
    } else {
      fin = med;
    }
  }
  return ini % k == 0LL ? ini - 1LL : ini;
}
