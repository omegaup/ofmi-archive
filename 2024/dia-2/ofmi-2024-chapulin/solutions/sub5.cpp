// Sub 4: Suma de prefijos y sufijos, la diferencia con Sub 3 es darse cuenta
// que no necesitas volver a calcular el mayor prefijo, solo acarrearlo.
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
  int mejor_a_la_derecha = 0;

  for (int i = n - 1; i >= 0; --i) {
    answer = std::max(answer, prefix_sum[i] + mejor_a_la_derecha);
    if (i + s < n) arr[i] += arr[i + s];
    mejor_a_la_derecha = std::max(mejor_a_la_derecha, arr[i]);
  }
  std::cout << answer << '\n';
}
