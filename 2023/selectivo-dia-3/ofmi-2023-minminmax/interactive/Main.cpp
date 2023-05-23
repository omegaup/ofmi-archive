#include <iostream>

#include "minminmax.h"

int minMinMaxOfficial(int n, int m, int A[]) {
  // Guardamos el indice del minimo y el maximo
  int min_id = 0;
  int max_id = 0;
  // Buscamos el minimo y el maximo
  for (int i = 0; i < n; ++i) {
    if (A[i] > A[max_id]) {
      max_id = i;
    }
    if (A[i] < A[min_id]) {
      min_id = i;
    }
  }

  int ans;
  if (m == 1) {
    // Si m es 1, la respuesta es el mayor elemento
    ans = A[max_id];
  } else if (m == 2) {
    // Si m es 2, la respuesta es el menor elemento de las esquinas
    ans = std::min(A[0], A[n - 1]);
  } else {
    // Si m es 3 o más, la respuesta es el menor elemento
    ans = A[min_id];
  }

  return ans;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Leemos n y m
  int n, m;
  std::cin >> n >> m;
  // Leemos el arreglo A
  int A[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }
  // Llamamos a la función de la participante
  int ans = minMinMax(n, m, A);
  // Llamamos a la función oficial
  int ans_official = minMinMaxOfficial(n, m, A);

  // Comparamos las respuestas
  std::cout << (ans == ans_official ? 1 : 0) << std::endl;

  return 0;
}
