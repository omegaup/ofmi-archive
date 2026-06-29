#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
/*
  Las aristas se hacen de forma aleatoria.

  14 pts
*/

const int oo = 1e5;

struct Estrella {
  int grado;
  int idx;
  int randomIdx;
};

struct ComparaRandom {
  bool operator()(Estrella a, Estrella b) const {
    return a.randomIdx < b.randomIdx;
  }
};

int main() {
  int n;
  std ::cin >> n;
  std ::priority_queue<Estrella, std ::vector<Estrella>, ComparaRandom> grados;

  for (int i = 0; i < n; i++) {
    int g;
    std ::cin >> g;

    if (g > 0) grados.push({g, i + 1, rand() % oo});
  }

  std ::vector<std ::pair<int, int>> conexiones;

  while (!grados.empty()) {
    Estrella a = grados.top();
    grados.pop();
    Estrella b = grados.top();
    grados.pop();

    conexiones.push_back({a.idx, b.idx});

    a.grado--;
    a.randomIdx = rand() % oo;
    b.grado--;
    b.randomIdx = rand() % oo;

    if (a.grado > 0) grados.push(a);
    if (b.grado > 0) grados.push(b);
  }

  std ::cout << conexiones.size() << "\n";

  for (auto arista : conexiones) {
    std ::cout << arista.first << " " << arista.second << "\n";
  }
}
