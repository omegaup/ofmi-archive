#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

/*
  Se usa una queue y los datos solo se ordenan una vez. Se gardan las aristas
  por parejas.

  14 pts
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

  for (auto g : grados_sin_ordenar) grados.push(g);

  std ::vector<std ::pair<int, int>> conexiones;

  while (!grados.empty()) {
    std ::pair<int, int> a = grados.front();
    grados.pop();
    std ::pair<int, int> b = grados.front();
    grados.pop();

    conexiones.push_back({a.second, b.second});
    a.first--;
    b.first--;

    if (a.first > 0) grados.push(a);
    if (b.first > 0) grados.push(b);
  }

  std ::cout << conexiones.size() << "\n";

  for (auto arista : conexiones) {
    std ::cout << arista.first << " " << arista.second << "\n";
  }
}
