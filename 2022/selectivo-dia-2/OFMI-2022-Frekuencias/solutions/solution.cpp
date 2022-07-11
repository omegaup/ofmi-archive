#include "frekuencias.h"

int frekuencia(int N, char S[]) {
  // Inicializar lista de prefijos para cada letra
  int prefixLetter[N + 1][26];
  for (int i = 0; i < 26; ++i) {
    prefixLetter[0][i] = 0;
  }

  // Precalculo
  for (int i = 1; i <= N; ++i) {
    // Acumular valores anteriores
    for (int j = 0; j < 26; ++j) {
      prefixLetter[i][j] = prefixLetter[i - 1][j];
    }
    // Aumentar letra actual
    ++prefixLetter[i][S[i - 1] - 'a'];
  }

  // Si ya supieramos cual es el caracter que mas se repite y cual
  // es el caracter que menos se repite, entonces podriamos calcular
  // la frekuencia con un barrido
  int respuesta = 0;
  for (int letra_mayor = 0; letra_mayor < 26; ++letra_mayor) {
    for (int letra_menor = 0; letra_menor < 26; ++letra_menor) {
      if (letra_mayor == letra_menor) continue;

      // Probamos todas las posibles combinaciones de 'caracter mas
      // repetido' y 'caracter menos repetido'
      // Complejidad O(26*26*N)

      int last_mayor = 0, last_menor = 0;
      int diff_menor_actual = N, diff_menor_idx = -1;
      for (int i = 1; i <= N; ++i) {
        int diff_actual =
            prefixLetter[i][letra_mayor] - prefixLetter[i][letra_menor];

        if (S[i - 1] - 'a' == letra_mayor) {
          last_mayor = i;
        } else if (S[i - 1] - 'a' == letra_menor) {
          last_menor = i;
        }
        while (diff_menor_idx + 1 < last_mayor &&
               diff_menor_idx + 1 < last_menor) {
          diff_menor_idx++;
          int diff_at_idx = prefixLetter[diff_menor_idx][letra_mayor] -
                            prefixLetter[diff_menor_idx][letra_menor];
          if (diff_at_idx < diff_menor_actual) {
            diff_menor_actual = diff_at_idx;
          }
        }

        if (last_menor > 0 && last_mayor > 0 &&
            respuesta < (diff_actual - diff_menor_actual)) {
          respuesta = diff_actual - diff_menor_actual;
        }
      }
    }
  }

  return respuesta;
}
