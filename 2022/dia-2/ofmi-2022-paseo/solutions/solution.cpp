#include <algorithm>
#include <iostream>

int main() {
  int n, k;

  std::cin >> n >> k;

  int arr[n], diferencias[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + n);

  for (int i = 0; i < n - 1; i++) {
    diferencias[i] = arr[i + 1] - arr[i];
  }

  std::sort(diferencias, diferencias + n - 1);

  int costo = 0;
  for (int i = 0; i < n - k; i++) {
    costo += diferencias[i];
  }

  std::cout << costo << '\n';
}
