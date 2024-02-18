#include <algorithm>
#include <iostream>

#define MAX_VAL 1000

int n;
int val;
bool cubeta[MAX_VAL + 1];

int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);

  // En la variable distintos almacenamos la cantidad de numeros
  // diferentes que hemos visto en el arreglo.
  int distintos = 0;

  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> val;

    if (!cubeta[val]) {
      // Si la cubeta en la posición del valor que acabamos de leer
      // no estaba marcada, significa que acabamos de encontrar un
      // nuevo valor.
      distintos++;
      cubeta[val] = true;
    }
  }

  std::cout << distintos << "\n";
}
