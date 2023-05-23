#include <algorithm>
#include <iostream>

#include "compresion.h"

/*
Si m es igual a 1, nos conviene contar la frecuencia de cada elemento y
devolver n - max(frecuencia), y aplastamos todos a ese numero
*/
int compresion(int n, int m, int A[]) {
  std::sort(A, A + n);
  int best = 0;
  int bestFreq = 0;
  int curr = 0;
  int freq = 0;
  for (int i = 0; i < n; i++) {
    if (i == 0 || A[i] != A[i - 1]) {
      if (freq > bestFreq) {
        bestFreq = freq;
        best = curr;
      }
      curr = A[i];
      freq = 1;
    } else {
      freq++;
    }
  }

  aplasta(best, best);
  return n - bestFreq;
}
