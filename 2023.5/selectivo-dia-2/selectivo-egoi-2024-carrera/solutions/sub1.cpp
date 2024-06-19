#include <algorithm>
#include <iostream>
#include <vector>

struct Momento_epico {
  double posicion;
  double tiempo;
  int nave1, nave2;
  // Si [existe = false] entonces nunca se intersectan. Se
  // "intersectan" en el infinito.
  bool existe;

  // Ordenar primero por tiempo, luego por posicion
  bool operator<(const Momento_epico& momento) {
    if (existe != momento.existe) {
      return existe;
    }
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
  momento.nave1 = nave1;
  momento.nave2 = nave2;
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

  // Ordenar por x's
  std::vector<std::pair<int, int>> naves(n);
  for (int i = 0; i < n; ++i) {
    naves[i] = {x[i], i};
  }
  std::sort(naves.begin(), naves.end());

  // Subtarea 1: m = 1
  if (m == 1) {
    // Encontrar primer momento epico
    Momento_epico primer_momento;
    primer_momento.existe = false;
    for (int i = 0; i < n - 1; i++) {
      Momento_epico nuevo_momento =
          obtener_cruce(naves[i].second, naves[i + 1].second);
      primer_momento =
          (primer_momento < nuevo_momento ? primer_momento : nuevo_momento);
    }
    std::cout << primer_momento.nave1 + 1 << " " << primer_momento.nave2 + 1
              << "\n";
    return 0;
  }
}
