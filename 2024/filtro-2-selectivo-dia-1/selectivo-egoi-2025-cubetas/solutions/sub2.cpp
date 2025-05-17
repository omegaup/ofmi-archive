// Sub2: Ordenar el arreglo y solo los elementos consecutivos
// serán parte de una matrioshka.

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  std::vector<int> arr(n, 0);

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::sort(arr.begin(), arr.end());

  int ans = 1;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] + 1 == arr[i + 1]) continue;
    ans++;
  }
  std::cout << ans << "\n";
}
