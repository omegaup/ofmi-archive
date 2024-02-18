#include <algorithm>

#include "energia.h"

typedef long long int lld;

const int MAXN = 302;

int energiaMax;
int energia[MAXN];

void avanza(int m, int k) {
  // Avanzo a los primeros m corredores k km
  for (int i = 0; i < m; ++i) {
    mueve(i, k);
    energia[i] -= k;
  }
}

int distribuyeEnergia(int m) {
  // La energía de los primeros m corredores la paso a los primeros
  int i = 0;
  int j = 1;
  while (j < m) {
    if (i == j) {
      j++;
      continue;
    }
    if (energia[i] == energiaMax) {
      i++;
      continue;
    }
    if (energia[j] == 0) {
      j++;
      continue;
    }
    int cnt = std::min(energiaMax - energia[i], energia[j]);
    pasaEnergia(j, i, cnt);
    energia[j] -= cnt;
    energia[i] += cnt;
  }
  while (energia[i] > 0) i++;
  return i;
}

void avanzaMaximo(int n, int L) {
  // Lleno la energía
  std::fill(energia, energia + n, L);
  energiaMax = L;
  while (n > 1) {
    int avanzo;
    if (n >= L) {
      // Con avanzar uno basta
      avanzo = 1;
    } else {
      int l = energia[n - 1];
      avanzo = std::max(1, l / n);
    }
    avanza(n, avanzo);
    n = distribuyeEnergia(n);
  }
  // Ya solo tengo un corredor con l litros, lo avanzo
  avanza(1, energia[0]);
}
