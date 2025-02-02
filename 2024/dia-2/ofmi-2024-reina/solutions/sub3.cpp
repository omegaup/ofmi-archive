// Subtarea 3: Solo hay torres y alfiles.
//
// En esta subtarea, guardaremos las diagonales y columnas atacadas
// por los alfiles y torres respectivamente.
//
// Para cada posicion de la reina, checamos que su fila, columna, y
// diagonales esten disponibles.
#include <iostream>

const int MaxN = 2e6 + 10;
bool estan_atacando_fila[MaxN];
bool estan_atacando_columna[MaxN];
bool estan_atacando_diagonal_principal[2 * MaxN];
bool estan_atacando_diagonal_secundaria[2 * MaxN];

int N;

bool estan_atacando_la_posicion(int x, int y) {
  return estan_atacando_fila[x] || estan_atacando_columna[y] ||
         estan_atacando_diagonal_principal[x - y + MaxN] ||
         estan_atacando_diagonal_secundaria[x + y];
}

std::pair<int, int> buscar_posicion_de_la_reina(int x_reina, int y_reina) {
  // Checar fila y columna
  for (int i = 1; i <= N; ++i) {
    if (!estan_atacando_la_posicion(i, y_reina)) {
      return std::make_pair(i, y_reina);
    }
    if (!estan_atacando_la_posicion(x_reina, i)) {
      return std::make_pair(x_reina, i);
    }
  }

  // Diagonal principal
  int menor = std::min(x_reina, y_reina);
  int x_diagonal = x_reina - menor + 1;
  int y_diagonal = y_reina - menor + 1;
  for (; x_diagonal <= N && y_diagonal <= N; ++x_diagonal, ++y_diagonal) {
    if (!estan_atacando_la_posicion(x_diagonal, y_diagonal)) {
      return std::make_pair(x_diagonal, y_diagonal);
    }
  }

  // Diagonal secundaria
  int suma = x_reina + y_reina;
  x_diagonal = 1;
  y_diagonal = suma - 1;
  if (suma - 1 > N) {
    x_diagonal = suma - N;
    y_diagonal = N;
  }
  for (; x_diagonal <= N && y_diagonal >= 1; ++x_diagonal, --y_diagonal) {
    if (!estan_atacando_la_posicion(x_diagonal, y_diagonal)) {
      return std::make_pair(x_diagonal, y_diagonal);
    }
  }

  return std::make_pair(-1, -1);
}

int main() {
  int K;
  std::cin >> N >> K;

  int x_reina, y_reina;
  std::cin >> x_reina >> y_reina;

  for (int i = 0; i < K; ++i) {
    char pieza;
    int x, y;
    std::cin >> pieza >> x >> y;
    if (pieza == 'T') {
      estan_atacando_fila[x] = true;
      estan_atacando_columna[y] = true;
    } else if (pieza == 'A') {
      estan_atacando_diagonal_principal[x - y + MaxN] = true;
      estan_atacando_diagonal_secundaria[x + y] = true;
    }
  }

  std::pair<int, int> respuesta = buscar_posicion_de_la_reina(x_reina, y_reina);
  if (respuesta.first == -1) {
    // No encontramos una posicion valida para la reina
    std::cout << "-1\n";
    return 0;
  }
  std::cout << respuesta.first << " " << respuesta.second << "\n";
  return 0;
}
