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

lli tam_flor_creciente(int indice_flor, lli tiempo) {
  // Crecimiento de la flor
  lli tam = std::min(M * tiempo, (lli)lims_flor[indice_flor]);

  // No hay limite de crecimiento
  if (tam == -1) {
    tam = M * tiempo;
  }

  // Crecimiento final
  return tam;
}

bool posicion_cubierta(int x, int y, int indice_flor, lli tiempo) {
  // Verificar si la posicion (x, y) esta cubierta por la flor
  // con indice "indice_flor" en el minuto "tiempo"

  // Crecimiento de la flor
  lli tam_flor = tam_flor_creciente(indice_flor, tiempo);

  // Limites de la flor con crecimiento
  lli inf_x = tallos[indice_flor].first - tam_flor;
  lli sup_x = tallos[indice_flor].first + tam_flor;
  lli inf_y = tallos[indice_flor].second - tam_flor;
  lli sup_y = tallos[indice_flor].second + tam_flor;

  // Checar que la posicion (x, y) este en los limites
  return inf_x <= x && x <= sup_x && inf_y <= y && y <= sup_y;
}

bool flores_conectadas(int A, int B, lli tiempo) {
  // Verificar si estan conectadas las flores A y B en el minuto "tiempo"

  // Crecimiento de las flores
  lli tam_A = tam_flor_creciente(A, tiempo);
  lli tam_B = tam_flor_creciente(B, tiempo);

  // Distancia entre los tallos
  int dist_xs = std::abs(tallos[A].first - tallos[B].first);
  int dist_ys = std::abs(tallos[A].second - tallos[B].second);
  int dist_flores = std::max(dist_xs, dist_ys);
  // Existe camino
  return dist_flores <= tam_A + tam_B + 1;
}

bool DFS(int flor_actual, int tiempo) {
  if (posicion_cubierta(x_salida, y_salida, flor_actual, tiempo)) {
    // Llegamos a la salida
    return true;
  }

  if (visitada[flor_actual]) {
    // Ya la habiamos visitado
    return false;
  }
  // Empezamos a explorar
  visitada[flor_actual] = true;
  for (int flor_siguiente = 0; flor_siguiente < tallos.size();
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
  // Inicializar arreglo de visitados
  visitada.resize(tallos.size());
  std::fill(visitada.begin(), visitada.end(), false);

  // Visitar las flores que cubran a la entrada
  for (int flor = 0; flor < tallos.size(); ++flor) {
    if (posicion_cubierta(x_entrada, y_entrada, flor, tiempo) &&
        DFS(flor, tiempo)) {
      // Encontramos la salida
      return true;
    }
  }
  // No encontramos la salida
  return false;
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
  // Leer cantidad de flores y constante de crecimiento
  std::cin >> N >> M;

  // Coordenadas de entrada y salida
  std::cin >> x_entrada >> y_entrada;
  std::cin >> x_salida >> y_salida;

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