// Sub1: Si procesamos las espias de izquierda a derecha, una espia vigila a 1 o
// a la siguiente espia. La primera vez que aparece un 1, crea un ciclo, ya que
// todos los anteriores fueron hacia adelante. Despues, cada vez que aparece un
// 1, se crea una rama que se junta con todas las espias del ciclo.

#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  bool ciclo_cerrado = false;
  int maximo_camino = 0, tamano_actual = 1, tamano_ciclo = 0;

  for (int i = 0; i < n; ++i, ++tamano_actual) {
    int u;
    std::cin >> u;
    if (u == 1) {
      if (ciclo_cerrado)
        maximo_camino = std::max(maximo_camino, tamano_ciclo + tamano_actual);
      else
        maximo_camino = tamano_ciclo = tamano_actual;

      ciclo_cerrado = true;
      tamano_actual = 0;
    }
  }
  std::cout << maximo_camino << '\n';
}
