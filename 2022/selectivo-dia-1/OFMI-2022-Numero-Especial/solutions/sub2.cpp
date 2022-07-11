#include "numeroespecial.h"

long long numeroEspecial(long long n, long long m, long long k) {
  return n + (n - 1LL) / (k - 1LL);
}
