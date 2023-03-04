#include <iostream>
#include <vector>

const int MaxN = 501;
int mapa[MaxN][MaxN];
bool visitados[MaxN][MaxN];

int main() {
  // Lectura de datos
  int N, M;
  std::cin >> N >> M;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> mapa[i][j];
    }
  }

  // Inicializar
  int x = N - 1, y = 0;
  visitados[N - 1][0] = true;

  // Recorrer mapa
  while (!(x == 0 && y == M - 1)) {
    if (mapa[x][y] == 0) {
      --x;  // Norte
    } else if (mapa[x][y] == 1) {
      ++y;  // Este
    } else if (mapa[x][y] == 2) {
      ++x;  // Sur
    } else if (mapa[x][y] == 3) {
      --y;  // Oeste
    }

    // Checar posicion nueva
    if (x < 0 || x == N || y < 0 || y == M) {
      break;  // Fuera del tablero
    }
    if (visitados[x][y]) {
      break;  // Esta en un ciclo
    }

    visitados[x][y] = true;
  }
  if (x == 0 && y == M - 1) {
    // Llego al objetivo
    std::cout << "0\n";
  } else {
    // No llego
    std::cout << "-1\n";
  }
}
