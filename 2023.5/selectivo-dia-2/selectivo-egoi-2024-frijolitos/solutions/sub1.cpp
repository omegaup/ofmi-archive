#include <algorithm>

#include "frijolitos.h"

std::pair<int, int> PeorMovimiento(int);

std::pair<int, int> MejorMovimiento(int N) {
  if (!N) return {0, 0};
  if (N & 1) return {PeorMovimiento(N - 1).first + 1, 1};

  const auto dividir = PeorMovimiento(N / 2);
  const auto menos_uno = PeorMovimiento(N - 1);

  if (dividir.first + N / 2 > menos_uno.first + 1)
    return {dividir.first + N / 2, N / 2};
  else
    return {menos_uno.first + 1, 1};
}

std::pair<int, int> PeorMovimiento(int N) {
  if (!N) return {0, 0};
  if (N & 1) return {MejorMovimiento(N - 1).first, 1};

  const auto dividir = MejorMovimiento(N / 2);
  const auto menos_uno = MejorMovimiento(N - 1);

  if (dividir.first < menos_uno.first)
    return {dividir.first, N / 2};
  else
    return {menos_uno.first, 1};
}

void frijolitos(long long N) {
  while (N) {
    const int C = MejorMovimiento(N).second;
    N -= C + tomar(C);
  }
}
