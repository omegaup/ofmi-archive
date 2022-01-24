#include <algorithm>
#include <iostream>

int main() {
  int n, k;

  std::cin >> n >> k;

  int arr[n];

  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }

  std::sort(arr, arr + n);

  int menor_altura = arr[0];
  int mayor_altura = arr[n - 1];
  int mayor_diferencia = arr[1] - arr[0];

  for (int i = 0; i < n - 1; i++) {
    mayor_diferencia = std::max(mayor_diferencia, arr[i + 1] - arr[i]);
  }

  int respuesta = mayor_altura - menor_altura;
  if (k >= 2) respuesta -= mayor_diferencia;

  std::cout << respuesta << '\n';
}
