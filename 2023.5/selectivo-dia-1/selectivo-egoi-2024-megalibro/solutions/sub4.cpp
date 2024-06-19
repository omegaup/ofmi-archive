#include <iostream>
#include <vector>

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, k;
  std::cin >> n >> k;

  std::vector<long long> A(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  /*
  dp[i] = El menor tiempo que se necesita para colorear el libro de tal forma
  que entre la página 0 y la i no hayan más de k páginas sin colorear. La
  respuesta será entonces dp[n-1].
  */
  std::vector<long long> dp(n, 0);

  for (int i = 0; i < n; i++) {
    if (i < k) {
      dp[i] = 0;
      continue;
    }

    dp[i] = A[i] + (i ? dp[i - 1] : 0);

    for (int j = 1; j <= k; j++) {
      int pos = i - j;
      if (pos < 0) break;
      dp[i] = std::min(dp[i], A[pos] + (pos ? dp[pos - 1] : 0));
    }
  }

  std::cout << dp[n - 1] << '\n';

  return 0;
}
