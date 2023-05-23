#include <algorithm>
#include <iostream>

#include "compresion.h"

int compresionOfficial(int n, int m, int A[]) {
  std::sort(A, A + n);

  int distinct = 1;
  int i = 0;
  int j = 0;
  int best = n;
  int bestA = -1, bestB = -1;
  for (i = 0; i < n; i++) {
    if (j < i) {
      distinct = 1;
      j = i;
    }
    while (j < n - 1 && (distinct < m || A[j + 1] == A[j])) {
      if (A[j] < A[j + 1]) {
        distinct++;
      }
      j++;
    }
    int cambiados = n - (j - i + 1);
    if (cambiados < best) {
      best = cambiados;
      bestA = A[i];
      bestB = A[j];
    }
    if (i < n - 1 && A[i] < A[i + 1]) {
      distinct--;
    }
  }

  return best;
}

const int MAXN = 300000;
int n, m;
int A[MAXN];
bool llamaste_a_aplastar = false;
int cambiados = 0;

void aplasta(int a, int b) {
  std::clog << "Llamando a aplasta(" << a << ", " << b << ")..." << std::endl;
  if (llamaste_a_aplastar) {
    std::cerr << "Llamaste a aplasta más de una vez!" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  llamaste_a_aplastar = true;
  if (a > b) {
    std::cerr << "Llamaste a aplasta con índices inválidos!" << std::endl;
    std::cout << 0 << std::endl;
    std::exit(0);
  }
  for (int i = 0; i < n; ++i) {
    if (A[i] < a) {
      A[i] = a;
      cambiados++;
    }
    if (A[i] > b) {
      A[i] = b;
      cambiados++;
    }
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n y m
  std::cin >> n >> m;
  int A_copy[n];
  // Leemos el arreglo A
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
    A_copy[i] = A[i];
  }
  // Llamamos a la función de la participante
  int ans = compresion(n, m, A);
  // Llamamos a la función oficial
  int ans_official = compresionOfficial(n, m, A_copy);

  int different_after_change = 1;
  std::sort(A, A + n);
  for (int i = 0; i < n - 1; ++i) {
    if (A[i] != A[i + 1]) {
      different_after_change++;
    }
  }

  // Comparamos las respuestas
  std::cout << (ans == ans_official && cambiados == ans_official &&
                        different_after_change <= m
                    ? 1
                    : 0)
            << std::endl;

  return 0;
}
