#include <iostream>
#include <vector>

//
long long simula(std::vector<int>& A, int C, int k) {
  long long s = 0;

  for (int i = 0; i < k; i++) {
    s += (long long)A[i];
    s -= (long long)C;
    s = std::max((long long)0, s);
  }
  s += (long long)A[k];

  return s;
}

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  // sub2: N <= 1000
  int N, C;
  std::cin >> N >> C;

  std::vector<int> A(N);

  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    // Calculamos cuántos grupos siguen pendientes de abordar.
    long long pendientes = simula(A, C, i);

    // Calculamos cuánto tiempo deberíamos esperar.
    long long espera = pendientes / (long long)C;
    if (espera < (long long)(N - i)) {
      std::cout << espera << " ";
    } else {
      std::cout << "-1 ";
    }
  }
  std::cout << "\n";

  return 0;
}