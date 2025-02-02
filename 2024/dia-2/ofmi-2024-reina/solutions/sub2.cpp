// Subtarea 2: Solo hay torres.
//
// En esta subtarea, solo hay torres, entonces podemos guardar que
// columnas y renglones son atacadas.
//
// Para cada fila libre, checamos que las posibles posiciones de la
// reina y verificamos si la columna no es atacada por una torre.
#include <iostream>

const int MaxN = 2e6 + 10;
bool estan_atacando_fila[MaxN];
bool estan_atacando_columna[MaxN];

int main() {
  int N, K;
  std::cin >> N >> K;

  int x_reina, y_reina;
  std::cin >> x_reina >> y_reina;

  // Consideramos que todas las piezas son torres, por lo que
  // directamente marcamos como atacadas las columna y filas
  for (int i = 0; i < K; ++i) {
    char pieza;
    int x, y;
    std::cin >> pieza >> x >> y;
    estan_atacando_fila[x] = true;
    estan_atacando_columna[y] = true;
  }

  if (!estan_atacando_fila[x_reina]) {
    for (int i = 1; i <= N; ++i) {
      if (!estan_atacando_columna[i]) {
        // Encontramos una posicion valida para la reina
        std::cout << x_reina << " " << i << "\n";
        return 0;
      }
    }
    // Todas las columnas fueron atacadas por torres
    std::cout << "-1\n";
    return 0;
  }

  if (!estan_atacando_columna[y_reina]) {
    for (int i = 1; i <= N; ++i) {
      if (!estan_atacando_fila[i]) {
        // Encontramos una posicion valida para la reina
        std::cout << i << " " << y_reina << "\n";
        return 0;
      }
    }
    // Todas las filas fueron atacadas por torres
    std::cout << "-1\n";
    return 0;
  }

  // Buscamos en las diagonales
  for (int i = 1; i <= N; ++i) {
    if (estan_atacando_fila[i]) continue;
    // x-y == a-b
    // y = x-a+b
    int columna_posible_reina = i - x_reina + y_reina;
    if (1 <= columna_posible_reina && columna_posible_reina <= N &&
        !estan_atacando_columna[columna_posible_reina]) {
      // Si es posible movernos en la diagonal principal
      std::cout << i << " " << columna_posible_reina << "\n";
      return 0;
    }

    columna_posible_reina = x_reina + y_reina - i;
    if (1 <= columna_posible_reina && columna_posible_reina <= N &&
        !estan_atacando_columna[columna_posible_reina]) {
      // Si es posible movernos en la diagonal secundaria
      std::cout << i << " " << columna_posible_reina << "\n";
      return 0;
    }
  }

  // Tampoco habia posiciones posibles en las columnas
  std::cout << "-1\n";
  return 0;
}
