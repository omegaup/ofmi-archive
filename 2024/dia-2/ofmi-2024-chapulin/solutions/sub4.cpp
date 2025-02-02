// Sub 4: Suma de prefijos y sufijos, para saber cual es la mejor posicion que
// complementa un sufijo buscamos el mayor entre todos los prefijos S posiciones
// atras (ojo que S ya es una optimizacion, porque bien podriamos usar T).
#include <iostream>
#include <vector>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  std::vector<int> arr(n);
  for (auto& a : arr) std::cin >> a;

  std::vector<int> prefix_sum(n);
  for (int i = 0; i < s; ++i) prefix_sum[i] = arr[i];
  for (int i = s; i < n; ++i) prefix_sum[i] = arr[i] + prefix_sum[i - s];

  int answer = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (i + s < n) arr[i] += arr[i + s];

    int mejor_prefix = 0;
    for (int j = 1; j < s && i - j >= 0; ++j)
      mejor_prefix = std::max(mejor_prefix, prefix_sum[i - j]);
    answer = std::max(answer, arr[i] + mejor_prefix);
  }
  std::cout << answer << '\n';
}
