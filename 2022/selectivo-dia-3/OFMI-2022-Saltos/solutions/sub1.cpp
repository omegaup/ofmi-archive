#include <vector>

#include "cobayasaltarina.h"

bool esPrimo(int v) {
  if (v == 1) {
    return false;
  }
  for (int i = 2; i < v; ++i) {
    if (v % i == 0) return false;
  }
  return true;
}

int cobayaSaltarina(int K, int N, int hoyos[]) {
  for (int i = (K + 1) / 2; i <= K; ++i) {
    bool found = false;
    for (int j = 0; j < N; ++j) {
      if (hoyos[j] == i) {
        found = true;
        break;
      }
    }
    if (!found && esPrimo(i)) {
      return i;
    }
  }
  return K + 1;
}
