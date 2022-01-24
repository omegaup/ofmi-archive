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
  int mayor_diferencia1 = arr[1] - arr[0];
  int mayor_diferencia2 = 0;

  for (int i = 0; i < n - 1; i++) {
    int diferencia = arr[i + 1] - arr[i];
    if (diferencia > mayor_diferencia1) {
      mayor_diferencia2 = mayor_diferencia1;
      mayor_diferencia1 = diferencia;
    } else if (diferencia > mayor_diferencia2) {
      mayor_diferencia2 = diferencia;
    }
  }

  int respuesta = mayor_altura - menor_altura;
  if (k >= 2) respuesta -= mayor_diferencia1;
  if (k >= 3) respuesta -= mayor_diferencia2;

  std::cout << respuesta << '\n';
}
