#include <algorithm>

#include "frijolitos.h"

constexpr int kMaxN = 1000000;

std::pair<int, int> memo_mejor[kMaxN];
std::pair<int, int> memo_peor[kMaxN];

std::pair<int, int> PeorMovimiento(int);

std::pair<int, int> MejorMovimiento(int N) {
  if (memo_mejor[N].second) return memo_mejor[N];
  if (!N) return {0, 0};
  if (N & 1) return memo_mejor[N] = {PeorMovimiento(N - 1).first + 1, 1};

  const auto dividir = PeorMovimiento(N / 2);
  const auto menos_uno = PeorMovimiento(N - 1);

  if (dividir.first + N / 2 > menos_uno.first + 1)
    return memo_mejor[N] = {dividir.first + N / 2, N / 2};
  else
    return memo_mejor[N] = {menos_uno.first + 1, 1};
}

std::pair<int, int> PeorMovimiento(int N) {
  if (memo_peor[N].second) return memo_peor[N];
  if (!N) return {0, 0};
  if (N & 1) return memo_peor[N] = {MejorMovimiento(N - 1).first, 1};

  const auto dividir = MejorMovimiento(N / 2);
  const auto menos_uno = MejorMovimiento(N - 1);

  if (dividir.first < menos_uno.first)
    return memo_peor[N] = {dividir.first, N / 2};
  else
    return memo_peor[N] = {menos_uno.first, 1};
}

void frijolitos(long long N) {
  while (N) {
    const int C = MejorMovimiento(N).second;
    N -= C + tomar(C);
  }
}
