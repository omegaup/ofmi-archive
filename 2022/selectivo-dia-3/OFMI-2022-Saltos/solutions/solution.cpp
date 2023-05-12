#include <iostream>
#include <unordered_set>
#include <vector>

#include "cobayasaltarina.h"
typedef long long int lld;

const int MAXN = 3000002;
bool criba[MAXN];

int cobayaSaltarina(int k, int n, int hoyos[]) {
  std::unordered_set<int> s;
  for (int idx = 0; idx < n; ++idx) {
    int x = hoyos[idx];
    for (int i = 2; i * i <= x; ++i) {
      if ((x % i) == 0) {
        s.insert(i);
        while ((x % i) == 0) {
          x /= i;
        }
      }
    }
    s.insert(x);
  }
  // criba
  if (s.count(2) == 0) {
    return 2;
  }
  for (lld i = 3; true; i += 2) {
    if (criba[i] == true) {
      continue;
    }
    if (s.count(i) == 0) {
      return i;
    }
    for (lld j = i * i; j < MAXN; j += i) {
      criba[j] = true;
    }
  }
  return -1;
}
