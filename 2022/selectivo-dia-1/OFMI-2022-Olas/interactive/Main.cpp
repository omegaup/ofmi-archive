#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#include "waves.h"

const int MAXN = 102;
int DP[MAXN][MAXN][MAXN];

int wavesOficial(int n, int k, int A[]) {
  // Copiar a un vector
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) arr[i] = A[i];

  // Mapear numeros a [0, n - 1]
  std::vector<int> nums = arr;
  std::sort(nums.begin(), nums.end());
  std::map<int, int> numToIdx;
  int idx = 0;
  for (int num : nums) {
    if (numToIdx.count(num) == 0) {
      numToIdx[num] = idx++;
    }
  }
  for (int i = 0; i < n; ++i) arr[i] = numToIdx[arr[i]];

  /*
    pos : Posicion actual
    a_pos : Numero en la posicion actual
    cambios_permitidos : Cantidad de cambios permitidos para despues* (para
    posisciones mayores a 'pos') DP[pos][a_pos][cambios_permitidos] = min( 1 +
    DP[posicion - 1][a_i][cambios_permitidos + cambio] si a_i > a_pos 0 +
    DP[posicion - 1][a_i][cambios_permitidos + cambio] si a_i <= a_pos ) donde
    cambio = 1 si a_pos != original_pos, 0 si no
  */

  // inf en todo
  int last_suff[n + 1][k + 2];
  int last_pref[n + 1][k + 2];
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j)
      for (int l = 0; l <= k + 1; ++l) {
        DP[i][j][l] = 1e9;
        last_suff[i][l] = 1e9;
        last_pref[i][l] = 1e9;
      }

  // Caso base (pos = 0)
  {
    int pos = 0;
    for (int a_pos = 0; a_pos < n; ++a_pos) {
      int cambio = (a_pos != arr[pos]);
      DP[pos][a_pos][k - cambio] = 0;
    }
    for (int cambios_permitidos = 0; cambios_permitidos <= k;
         ++cambios_permitidos) {
      // Prefijo [:i]
      last_pref[0][cambios_permitidos] = DP[pos][0][cambios_permitidos];
      for (int a_pos = 1; a_pos < n; ++a_pos) {
        last_pref[a_pos][cambios_permitidos] =
            DP[pos][a_pos][cambios_permitidos];
        last_pref[a_pos][cambios_permitidos] =
            std::min(last_pref[a_pos][cambios_permitidos],
                     last_pref[a_pos - 1][cambios_permitidos]);
      }
      // Sufijo [i:]
      last_suff[n - 1][cambios_permitidos] = DP[pos][n - 1][cambios_permitidos];
      for (int a_pos = n - 1; a_pos >= 0; --a_pos) {
        last_suff[a_pos][cambios_permitidos] =
            DP[pos][a_pos][cambios_permitidos];
        last_suff[a_pos][cambios_permitidos] =
            std::min(last_suff[a_pos][cambios_permitidos],
                     last_suff[a_pos + 1][cambios_permitidos]);
      }
    }
  }

  // O(n^3)
  for (int pos = 1; pos < n; ++pos) {
    // O(n^2)
    for (int a_pos = 0; a_pos < n; ++a_pos) {
      int cambio = (a_pos != arr[pos]);
      for (int cambios_permitidos = 0; cambios_permitidos <= k;
           ++cambios_permitidos) {
        int minimo_pos = last_pref[a_pos][cambios_permitidos + cambio];
        minimo_pos = std::min(
            minimo_pos, 1 + last_suff[a_pos + 1][cambios_permitidos + cambio]);
        DP[pos][a_pos][cambios_permitidos] = minimo_pos;
      }
    }

    // O(n^2)
    for (int cambios_permitidos = 0; cambios_permitidos <= k;
         ++cambios_permitidos) {
      // Prefijo [:i]
      last_pref[0][cambios_permitidos] = DP[pos][0][cambios_permitidos];
      for (int a_pos = 1; a_pos < n; ++a_pos) {
        last_pref[a_pos][cambios_permitidos] =
            DP[pos][a_pos][cambios_permitidos];
        last_pref[a_pos][cambios_permitidos] =
            std::min(last_pref[a_pos][cambios_permitidos],
                     last_pref[a_pos - 1][cambios_permitidos]);
      }
      // Sufijo [i:]
      last_suff[n - 1][cambios_permitidos] = DP[pos][n - 1][cambios_permitidos];
      for (int a_pos = n - 1; a_pos >= 0; --a_pos) {
        last_suff[a_pos][cambios_permitidos] =
            DP[pos][a_pos][cambios_permitidos];
        last_suff[a_pos][cambios_permitidos] =
            std::min(last_suff[a_pos][cambios_permitidos],
                     last_suff[a_pos + 1][cambios_permitidos]);
      }
    }
  }

  int respuesta = 1e9;
  for (int a_pos = 0; a_pos < n; ++a_pos) {
    for (int cambios_permitidos = 0; cambios_permitidos <= k;
         ++cambios_permitidos) {
      respuesta = std::min(respuesta, DP[n - 1][a_pos][cambios_permitidos]);
    }
  }
  return respuesta;
}

int main() {
  int n, k;
  std::cin >> n >> k;
  int A[n];
  for (int i = 0; i < n; ++i) {
    std::cin >> A[i];
  }

  int expected = wavesOficial(n, k, A);
  int contest = waves(n, k, A);
  fprintf(stderr, "got %lld, expected %lld", contest, expected);
  std::cout << (contest == expected ? "1.00\n" : "0.00\n");
}
