// Imprime S
#include <iostream>

const int MAXN = 1001;

int n, m;
int tablero[MAXN][MAXN];

int main() {
  std::cin >> n >> m;
  int S = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] > 1) {
        S = tablero[i][j];
      }
    }
  }
  std::cout << S << std::endl;
  return 0;
}