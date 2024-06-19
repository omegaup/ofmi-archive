#include <algorithm>
#include <iostream>
#include <vector>

struct Momento_epico {
  double posicion;
  double tiempo;
  int nave1, nave2;
  // Si [existe = false] entonces nunca se intersectan.
  bool existe;

  // Ordenar primero por tiempo, luego por posicion
  bool operator<(const Momento_epico& momento) {
    return tiempo < momento.tiempo ||
           (tiempo == momento.tiempo && posicion < momento.posicion);
  }
};

const int MaxN = 1e5 + 10;
int n, m;
int x[MaxN], v[MaxN];

// Posicion y tiempo donde se intersectan.
// El valor [existe] es [false] si nunca se intersectan.
Momento_epico obtener_cruce(int nave1, int nave2) {
  if (x[nave2] < x[nave1]) {
    std::swap(nave1, nave2);
  }

  Momento_epico momento;
  momento.nave1 = nave1 + 1;
  momento.nave2 = nave2 + 1;
  if (v[nave1] <= v[nave2]) {
    momento.existe = false;
    return momento;
  }

  momento.existe = true;
  // x[nave1] + v[nave1]*t = x[nave2] + v[nave2]*t
  momento.tiempo = (x[nave1] - x[nave2] + 0.0) / (v[nave2] - v[nave1]);
  momento.posicion = (x[nave1] + v[nave1] * momento.tiempo);
  return momento;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);
  std::cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    std::cin >> x[i] >> v[i];
  }

  // Subtarea 3: n <= 1000
  // Generar todos los momentos, ordenar y generar
  std::vector<Momento_epico> momentos;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      Momento_epico momento = obtener_cruce(i, j);
      if (momento.existe) momentos.push_back(momento);
    }
  }
  std::sort(momentos.begin(), momentos.end());

  for (int i = 0; i < m; ++i)
    std::cout << momentos[i].nave1 << " " << momentos[i].nave2 << "\n";
  return 0;
}
