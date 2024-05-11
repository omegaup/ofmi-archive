#include <algorithm>
#include <iostream>

#define MAX_N 200000

int n;
int F[MAX_N];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> F[i];
  }

  // En la variable distintos almacenamos la cantidad de numeros
  // diferentes que hemos visto en el arreglo; aumentamos en uno su
  // valor cada que vemos un cambio de número.
  int distintos = 1;
  for (int i = 1; i < n; i++) {
    if (F[i] != F[i - 1]) {
      distintos++;
    }
  }

  std::cout << distintos << "\n";
}
