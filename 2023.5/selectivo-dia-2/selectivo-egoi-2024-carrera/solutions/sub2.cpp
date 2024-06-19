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

  // Subtarea 2: Hay una sola nave con velocidad distinta

  // Encontrar el distinto
  // Primero encontrar el comun
  std::vector<int> velocidades;
  for (int i = 0; i < n; ++i) {
    velocidades.push_back(v[i]);
  }
  std::sort(velocidades.begin(), velocidades.end());
  int velocidad_comun = velocidades[1];
  int nave_unica = -1;
  for (int i = 0; i < n; ++i) {
    if (v[naves[i].second] != velocidad_comun) {
      nave_unica = i;
    }
  }

  if (v[naves[nave_unica].second] < velocidad_comun) {
    // Le alcanzaran naves por detras
    for (int i = 0; i < m; ++i) {
      std::cout << naves[nave_unica - i - 1].second + 1 << " "
                << naves[nave_unica].second + 1 << "\n";
    }
  } else {
    // La nave alcanzara a otras naves
    for (int i = 0; i < m; ++i) {
      std::cout << naves[nave_unica].second + 1 << " "
                << naves[nave_unica + i + 1].second + 1 << "\n";
    }
  }
  return 0;
}
