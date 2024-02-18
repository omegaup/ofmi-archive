#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

const int MAXN = 1e5;
int P[MAXN + 1];                  // Arreglo para guardar las mediciones
std::pair<int, int> R[MAXN + 1];  // Arreglo para guardar los rangos

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  // Leemos la variable N
  int N;
  std::cin >> N;
  // Creamos un vector para guardar puntos en la recta
  // de la forma [posicion, [tipo(inicio de rango, fin de rango, medición),
  // indice]]
  std::vector<std::pair<int, std::pair<int, int>>> points;
  for (int i = 0; i < N; i++) {
    std::cin >> P[i];                  // Leemos las mediciones
    points.push_back({P[i], {0, i}});  // Los agragamos al vector
  }
  for (int i = 0; i < N; i++) {
    int l, r;
    std::cin >> l >> r;  // Leemos los rangos
    R[i] = {l, r};
    points.push_back({l, {-1, i}});  // Insertamos inicio en el vector
    points.push_back({r, {1, i}});   // Insertamos fin en el vector
  }
  // Ordenamos los puntos en la recta
  std::sort(points.begin(), points.end());

  // Usamos un set para guardar los rangos activos
  // y cual es el que tiene el minimo fin
  std::set<std::pair<int, int>> st;
  std::vector<int> res(N, -1);  // Arreglo de respuestas
  bool fin = true;              // Ver si pudimos encontrar un rango
  // para cada medición
  for (auto [x, p] : points) {
    if (p.first == 0) {  // Si es una medición P
      if (st.empty()) {  // Si no hay rangos disponibles
        fin = false;
        break;
      }
      auto it = st.begin();        // Toma el que tiene menor fin
      res[it->second] = p.second;  // Guarda la respuesta
      st.erase(it);                // Lo borra del set de rangos disponibles
    } else if (p.first == -1) {    // Si es un punto de inicio
      st.insert({R[p.second].second, p.second});  // Agregalo al set
    } else if (p.first == 1) {                    // Si es un punto de fin
      st.erase({x, p.second});                    // Borralo del set
    }
  }
  if (fin) {  // Imprime sin espacio al final de la linea
    // y con un salto de linea al final
    std::cout << res[0];
    for (int i = 1; i < N; i++) {
      std::cout << ' ' << res[i];
    }
    std::cout << '\n';
  } else
    std::cout << -1 << '\n';  // Imprime que no se pudo con salto
  // de linea al final
  return 0;
}