#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/*
  Se usa una queue, los datos se ordenan 1 vez. Se acomodan las primero todas
  conexiones de cada nodo.

  39 pts
*/

int main() {
  int n;
  std ::cin >> n;
  std ::queue<std ::pair<int, int>> grados;
  std ::vector<std ::pair<int, int>> grados_sin_ordenar;

  for (int i = 0; i < n; i++) {
    int g;
    std ::cin >> g;

    if (g > 0) grados_sin_ordenar.push_back({g, i + 1});
  }

  sort(grados_sin_ordenar.begin(), grados_sin_ordenar.end());
  reverse(grados_sin_ordenar.begin(), grados_sin_ordenar.end());

  for (auto g : grados_sin_ordenar) grados.push(g);

  std ::vector<std ::pair<int, int>> conexiones;

  while (!grados.empty()) {
    std ::pair<int, int> curr = grados.front();
    grados.pop();

    for (int i = 0; i < curr.first; i++) {
      std ::pair<int, int> b = grados.front();
      grados.pop();
      b.first--;

      conexiones.push_back({curr.second, b.second});

      if (b.first > 0) grados.push(b);
    }
  }

  std ::cout << conexiones.size() << "\n";

  for (auto arista : conexiones) {
    std ::cout << arista.first << " " << arista.second << "\n";
  }
}
