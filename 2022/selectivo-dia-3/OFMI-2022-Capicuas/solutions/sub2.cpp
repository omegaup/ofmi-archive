#include <algorithm>
#include <cstring>
#include <iostream>

typedef long long int lld;

lld build(int n, char A[]) {
  lld num = 0;
  for (int i = 0; i < n; ++i) {
    num *= 10;
    num += A[i] - '0';
  }
  return num;
}

/*
capicua[i] -> 1 si es, 0 si no es
sum[i] -> suma xor de capicua de 1 a i
[i, j] queremos contarlo si sum[j] ^ sum[i-1] == 0
*/

const lld MOD = 1000000007;

lld triangular(lld x) {
  x %= MOD;
  return (x * (x - 1) / 2) % MOD;
}

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

lld nextCapicua(lld x) {
  while (!isCapicua(++x)) {
  }
  return x;
}

lld evenSubranges(lld x) {
  if (x < 0) {
    return -1;
  }
  int parity = 0;
  lld curr = 1;  // Current capicua
  lld ans = 0;   // [0, curr)
  while (curr <= x) {
    lld sig = nextCapicua(curr);
    if (parity == 0) {
      ans += std::min(sig, x + 1) - curr;
      ans %= MOD;
    }
    curr = sig;
    parity ^= 1;
  }
  return ans;
}

lld oddSubranges(lld x) { return (x - evenSubranges(x) + MOD) % MOD; }

int subrangosBonitos(long long A, long long B) {
  lld even = (evenSubranges(B) - evenSubranges(A - 2) + MOD) % MOD;
  lld odd = (oddSubranges(B) - oddSubranges(A - 2) + MOD) % MOD;
  return (triangular(even) + triangular(odd)) % MOD;
}
