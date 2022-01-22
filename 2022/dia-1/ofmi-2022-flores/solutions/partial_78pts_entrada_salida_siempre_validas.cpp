#include <iostream>
#include <queue>
#include <vector>
typedef long long int lli;

int N, M;
int x_entrada, y_entrada;
int x_salida, y_salida;
std::vector<std::pair<int, int>> tallos;
std::vector<int> lims_flor;
std::vector<bool> visitada;

bool flores_conectadas(int A, int B, lli tiempo) {
  // Verificar si estan conectadas las flores A y B en el minuto "tiempo"

  // Crecimiento de las flores
  lli tam_A = std::min(M * tiempo, (lli)lims_flor[A]);
  lli tam_B = std::min(M * tiempo, (lli)lims_flor[B]);
  // No hay limites de crecimiento
  if (tam_A == -1) {
    tam_A = M * tiempo;
  }
  if (tam_B == -1) {
    tam_B = M * tiempo;
  }

  // Distancia entre los tallos
  int dist_xs = std::abs(tallos[A].first - tallos[B].first);
  int dist_ys = std::abs(tallos[A].second - tallos[B].second);
  int dist_flores = std::max(dist_xs, dist_ys);
  // Existe camino
  return dist_flores <= tam_A + tam_B + 1;
}

bool DFS(int flor_actual, int tiempo) {
  if (flor_actual == 1) {
    // Llegamos a la salida
    return true;
  }
  if (visitada[flor_actual]) {
    // Ya la habiamos visitado
    return false;
  }
  // Empezamos a explorar
  visitada[flor_actual] = true;
  for (int flor_siguiente = 1; flor_siguiente < tallos.size();
       ++flor_siguiente) {
    if (flores_conectadas(flor_actual, flor_siguiente, tiempo)) {
      if (DFS(flor_siguiente, tiempo)) {
        // Encontramos la salida
        return true;
      }
      // Si no, seguimos buscando
    }
  }
  // No encontramos la salida
  return false;
}

bool es_posible(int tiempo) {
  visitada.resize(tallos.size());
  std::fill(visitada.begin(), visitada.end(), false);
  return DFS(0, tiempo);
}

int binaria_flores() {
  if (!es_posible(3e5)) {
    // No fue posible llegar a la salida
    return -1;
  }

  // inferior no se puede
  // superior si se puede
  int inferior = -1, superior = 3e5, medio;
  while (inferior + 1 < superior) {
    medio = (inferior + superior) / 2;
    if (es_posible(medio)) {
      superior = medio;
    } else {
      inferior = medio;
    }
  }
  return superior;
}

int main() {
  /*
    Solución parcial:
    En esta solución, la entrada y salida se consideran como posiciones válidas
    para pisar, aún y sin estar cubiertas por una flor.
  */

  // Leer cantidad de flores y constante de crecimiento
  std::cin >> N >> M;

  // Coordenadas de entrada y salida
  std::cin >> x_entrada >> y_entrada;
  std::cin >> x_salida >> y_salida;
  // Incluir entrada y salida como flores que no crecen
  tallos.push_back({x_entrada, y_entrada});
  lims_flor.push_back(0);
  tallos.push_back({x_salida, y_salida});
  lims_flor.push_back(0);

  // Leer posiciones de los tallos
  for (int i = 0; i < N; ++i) {
    int x, y;
    std::cin >> x >> y;
    tallos.push_back({x, y});
  }

  // Leer limites de crecimiento
  for (int i = 0; i < N; ++i) {
    int lim_flor;
    std::cin >> lim_flor;
    lims_flor.push_back(lim_flor);
  }

  // Imprimir respuesta
  std::cout << binaria_flores() << '\n';
}