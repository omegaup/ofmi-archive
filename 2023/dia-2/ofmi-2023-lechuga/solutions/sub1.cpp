// Esta solución parcial solo checa cuántas cobayas llegan a la lechuga y eso
// imprime
#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>

const int MAXN = 1002;

int n, m;
int tablero[MAXN][MAXN];

int main() {
  std::cin >> n >> m;
  int x = -1, y = -1;
  int S = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] > 1) {
        x = i;
        y = j;
        S = tablero[i][j];
      }
    }
  }

  std::vector<int> arr;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tablero[i][j] == 1) {
        arr.push_back(std::abs(i - x) + std::abs(j - y));
      }
    }
  }

  std::sort(arr.begin(), arr.end());

  int t = 0;
  int i = 0;  // Indice del siguiente en comer (o bien, los que están comiendo)
  while (S > 0 && i < arr.size()) {
    S -= (arr[i] - t - 1) * i;
    t = arr[i];      // Avanzo hasta el tiempo t para empezar a comer
    int faltan = i;  // Los que faltan por comer en el tiempo t
    while (i < arr.size() && arr[i] == t && S > 0) {
      i++;
      S--;
    }
    S -= faltan;  // Los que no comieron en el tiempo t
  }

  std::cout << arr.size() - i << std::endl;
  return 0;
}
