// Sub 3: Vamos a tomar la maxima suma eligiendo dos posiciones en el arreglo,
// las cuales se conectaran con el turbo salto, despues agarramos todos los
// elementos hacia atras y hacia adelante en brincos de tamano S.
#include <iostream>
#include <vector>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  std::vector<int> arr(n);
  for (auto& a : arr) std::cin >> a;

  int answer = 0;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int sum = 0;
      for (int k = i; k >= 0; k -= s) sum += arr[k];
      for (int k = j; k < n; k += s) sum += arr[k];
      answer = std::max(answer, sum);
    }
  }
  std::cout << answer << '\n';
}
