#include <iostream>
#include <queue>
#include <vector>
typedef long long lld;
typedef std::pair<lld, lld> pii;

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  // Leemos n y k
  int n, k;
  std::cin >> n >> k;
  // Leemos los elementos del arreglo
  std::vector<lld> A(n, 0);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  /*
  dp[i] = El menor tiempo que se necesita para colorear el libro de tal forma
  que entre la página 0 y la i no hayan más de k páginas sin colorear La
  respuesta será entonces dp[n-1]
  */
  std::vector<lld> dp(n, 0);
  // En una deque guardaremos {A[i] + dp[i-1], i} para poder tomar el mínimo
  std::deque<pii> dq;
  for (int i = 0; i < n; i++) {
    // Insertamos el elemento actual en la deque
    pii p = {A[i] + (i ? dp[i - 1] : 0), i};
    while (!dq.empty() && dq.back() >= p) dq.pop_back();
    dq.push_back(p);
    // Calculamos dp[i]
    if (i < k) {
      // Nos conviene no colorear las página i
      dp[i] = 0;
    } else {
      // Debemos asegurar que haya una página coloreada entre la i-k y la i
      // Si decidimos colorear la página j, entonces el tiempo que se necesita
      // es A[j] + dp[j-1]. Tomamos el mínimo de todos los j posibles
      while (dq.front().second < i - k) dq.pop_front();
      dp[i] = dq.front().first;
    }
  }

  std::cout << dp[n - 1] << '\n';

  return 0;
}
