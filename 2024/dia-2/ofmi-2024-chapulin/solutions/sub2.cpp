// Sub 2: Como todos los valores del arreglo son iguales, simplemente podemos
// calcular cuantos brincos vamos a poder dar desde la posicion 0.
// El turbo salto siempre nos conviene darlo de tamano 1, solo para agregar un
// valor mas a la ruta, sin embargo, esto no es posible cuando N % S == 1.
#include <iostream>
#include <vector>

int main() {
  int n, s, t, v;
  std::cin >> n >> s >> t >> v;
  std::cout << v * (((n + s - 1) / s) + ((n % s == 1) ? 0 : 1)) << '\n';
}
