#include <algorithm>
#include <cstring>
#include <iostream>

typedef long long lld;

bool isCapicua(lld x) {
  lld inv = 0;
  lld num = x;
  while (num > 0) {
    inv *= 10;
    inv += num % 10;
    num /= 10;
  }
  return inv == x;
}

int subrangosBonitos(lld A, lld B) {
  int ans = 0;
  for (lld i = A; i <= B; ++i) {
    int parity = 0;
    for (lld j = i; j <= B; ++j) {
      if (isCapicua(j)) {
        parity ^= 1;
      }
      if (parity == 0) {
        ans++;
      }
    }
  }
  return ans;
}
