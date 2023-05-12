#include <vector>

#include "cobayasaltarina.h"

std::vector<int> hoyosG;
bool checarPrimo(int v) {
  for (int hoyo : hoyosG) {
    if (hoyo % v == 0) return false;
  }
  return true;
}

bool esPrimo(int v) {
  for (int i = 2; i * i <= v; ++i) {
    if (v % i == 0) return false;
  }
  return true;
}

int cobayaSaltarina(int K, int N, int hoyos[]) {
  for (int i = 0; i < N; ++i) hoyosG.push_back(hoyos[i]);
  for (int i = 2; i <= 2 * K; ++i) {
    if (esPrimo(i) && checarPrimo(i)) {
      return i;
    }
  }
}
