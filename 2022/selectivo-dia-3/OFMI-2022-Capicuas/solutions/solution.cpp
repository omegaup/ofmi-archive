#include <stdlib.h>

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>

typedef long long lld;

lld buildStr(const std::string& s) {
  lld num = 0;
  for (int i = 0; i < s.size(); ++i) {
    num *= 10;
    num += s[i] - '0';
  }
  return num;
}

std::string toStr(lld x) {
  std::string s;
  while (x > 0) {
    s.push_back((x % 10) + '0');
    x /= 10;
  }
  std::reverse(s.begin(), s.end());
  return s;
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

void nextCapicua(std::string& s) {
  int r = s.size() / 2;
  int l = s.size() & 1 ? r : r - 1;
  while (s[l] == '9') {
    s[l] = s[r] = '0';
    if (l == 0) {
      s[0] = '1';
      for (int i = 1; i < s.size(); ++i) {
        s[i] = '0';
      }
      s.push_back('1');
      return;
    }
    l--;
    r++;
  }
  if (s[l] != '9') {
    s[l]++;
    if (l != r) {
      s[r]++;
    }
  }
}

lld evenSubranges(lld x) {
  if (x < 0) {
    return 0;
  }
  int parity = 1;
  std::string currStr = toStr(1);  // Current capicua
  lld curr = 1;
  lld ans = 1;  // [0, curr)
  while (curr <= x) {
    nextCapicua(currStr);
    auto sig = buildStr(currStr);
    // std::cout << curr << " -> " << sig << std::endl;
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
