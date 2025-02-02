// Sub 1: Para T=0 es suficiente con checar cual serie de brincos de tamano S
// acumula mas porque no podemos cambiar de "carril".
#include <iostream>
#include <vector>

int main() {
  int n, s, t;
  std::cin >> n >> s >> t;

  int answer = 0;
  std::vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> arr[i];
    if (i - s >= 0) arr[i] += arr[i - s];
    answer = std::max(answer, arr[i]);
  }
  std::cout << answer << '\n';
}
