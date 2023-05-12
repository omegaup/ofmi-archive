#include <algorithm>
#include <vector>

#include "cobayasaltarina.h"

const int MaxN = 2000000;
int numCompuesto[MaxN];
bool hoyosChicos[MaxN];
bool candidato[MaxN];

int encontrarDivisor(int n) {
  if (n % 2 == 0) return 2;
  for (int i = 3; i <= n / i; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}

int cobayaSaltarina(int k, int n, int hoyos[]) {
  // Dividir en hoyos grandes (> 10^5) y chicos
  std::vector<int> hoyosGrandes;
  for (int i = 0; i < n; ++i) {
    if (hoyos[i] < MaxN) {
      hoyosChicos[hoyos[i]] = true;
    } else {
      hoyosGrandes.push_back(hoyos[i]);
    }
  }

  // Criba normal (guarda un numero primo que divide al numero)
  numCompuesto[0] = numCompuesto[1] = 1;
  for (int num = 2; num < MaxN; ++num) {
    if (!numCompuesto[num]) {
      // 'num' es un numero primo
      numCompuesto[num] = num;
      bool coolPrimo = !hoyosChicos[num];  // Si esta sobre un hoyo, no es cool
      if (num < MaxN / num) {
        for (int multiplos = num * num; multiplos < MaxN; multiplos += num) {
          numCompuesto[multiplos] = num;
          // Checamos entre los multiplos del primo
          if (hoyosChicos[multiplos]) {
            coolPrimo = false;
            int hoyoChiquito = multiplos;
            // El numero sin potencias de 'num' tambien es 'malo' para
            // los demas primos
            while (hoyoChiquito % num == 0) {
              hoyoChiquito /= num;
            }
            hoyosChicos[hoyoChiquito] = true;
          }
        }
      }
      // Si se mantuvo 'true', entonces paso el filtro de primos chicos
      candidato[num] = coolPrimo;
    }
  }

  // Los hoyos grandes estan en [10^5, 10^9], entonces, son compuestos con un
  // divisor primo menor a 10^5 o son un numero primo.
  // O(sqrt(k)) por hoyo grande
  for (int hoyoGrande : hoyosGrandes) {
    int primo = encontrarDivisor(hoyoGrande);
    while (hoyoGrande > 1) {
      if (primo < MaxN) {
        candidato[primo] = false;
      }
      while (hoyoGrande % primo == 0 && primo > 1) {
        hoyoGrande /= primo;
      }
      // Obtener siguiente divisor no trivial
      if (hoyoGrande > MaxN) {
        primo = encontrarDivisor(hoyoGrande);
      } else {
        primo = numCompuesto[hoyoGrande];
      }
    }
  }

  // Encontrar primer candidato valido
  for (int num = 2; num < MaxN; ++num) {
    if (candidato[num]) {
      return num;
    }
  }
  // Hay que extender los limites de N
  return MaxN;
}
