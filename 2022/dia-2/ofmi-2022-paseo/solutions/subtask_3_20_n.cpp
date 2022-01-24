#include <algorithm>
#include <iostream>

int main() {
  int n, k;

  std::cin >> n >> k;

  int arr[25], diferencias[25];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (arr[j] > arr[i]) {
        std::swap(arr[i], arr[j]);
      }
    }
  }

  for (int i = 0; i < n - 1; i++) {
    diferencias[i] = arr[i + 1] - arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < i; j++) {
      if (diferencias[j] > diferencias[i]) {
        std::swap(diferencias[i], diferencias[j]);
      }
    }
  }

  int costo = 0;
  for (int i = 0; i < n - k; i++) {
    costo += diferencias[i];
  }

  std::cout << costo << '\n';
}
