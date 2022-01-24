#include <stdlib.h>

#include <iostream>
int tableroMaximo = 102;
int inf = 1e9;

int tablero[102][102];

int main() {
  int n, m, origenX, origenY, destinoX, destinoY;
  std::cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] == 2) {
        origenY = i;
        origenX = j;
      }
    }
  }

  std::cin >> destinoY >> destinoX;
  // Solo imprimir la diferencia de distancia o si no se puede llegar por la
  // distancia diagonal, -1
  int sol;
  if ((origenY - destinoY) < abs(origenX - destinoX)) {
    sol = -1;
  } else {
    sol = origenY - destinoY;
  }
  sol = std::max(sol, -1);
  std::cout << sol;
}
