#include <algorithm>
#include <iostream>
#include <queue>

const int MaxN = 1010;

int movs[8][2] = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                  {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int mapa[MaxN][MaxN];
bool visitados[MaxN][MaxN];

int N, M;
int x_entrada, y_entrada;
int x_salida, y_salida;
int x_tallos[MaxN], y_tallos[MaxN];
int limite[MaxN];

int tam_flor(int indice, int tiempo) {
  // Calculamos el crecimiento de la flor
  int tam = std::min(limite[indice], M * tiempo);
  if (tam == -1) {
    tam = M * tiempo;
  }
  return tam;
}

/// SUBTAREA 1
bool expandir_flores(int tiempo) {
  bool modificacion = false;
  // Trazar cada flor
  for (int i = 0; i < N; ++i) {
    // Expansion de la flor
    int tam_flor_actual = tam_flor(i, tiempo);
    int minX = std::max(x_tallos[i] - tam_flor_actual, 0);
    int maxX = std::min(x_tallos[i] + tam_flor_actual, MaxN - 1);
    int minY = std::max(y_tallos[i] - tam_flor_actual, 0);
    int maxY = std::min(y_tallos[i] + tam_flor_actual, MaxN - 1);

    // Marcar zonas cubiertas
    for (int a = minX; a <= maxX; ++a) {
      for (int b = minY; b <= maxY; ++b) {
        if (mapa[a][b] == 0) {
          mapa[a][b] = 1;
          modificacion = true;
        }
      }
    }
  }
  // Si cambio el mapa
  return modificacion;
}

bool llegamos_al_final() {
  if (mapa[x_entrada][y_entrada] == 0 || mapa[x_salida][y_salida] == 0) {
    // Todavia no cubrimos la entrada o salida
    return false;
  }
  for (int i = 0; i < MaxN; ++i) {
    for (int j = 0; j < MaxN; ++j) {
      visitados[i][j] = false;
    }
  }

  std::queue<std::pair<int, int>> bfs;
  bfs.push({x_entrada, y_entrada});
  visitados[x_entrada][y_entrada] = true;

  while (!bfs.empty()) {
    int x = bfs.front().first;
    int y = bfs.front().second;
    bfs.pop();

    if (x == x_salida && y == y_salida) {
      return true;
    }

    for (int k = 0; k < 8; ++k) {
      int sig_x = x + movs[k][0];
      int sig_y = y + movs[k][1];
      if (0 <= sig_x && sig_x < MaxN && 0 <= sig_y && sig_y < MaxN) {
        // Posicion valida
        if (mapa[sig_x][sig_y] > 0 && !visitados[sig_x][sig_y]) {
          // Cubierta por una flor y sin ser visitada
          visitados[sig_x][sig_y] = true;
          bfs.push({sig_x, sig_y});
        }
      }
    }
  }
  // No se logro llegar a la salida
  return false;
}

/// SUBTAREA 2
bool es_posible(int tiempo) {
  std::vector<std::pair<int, int>> flores;
  for (int i = 0; i < N; ++i) {
    int tam = tam_flor(i, tiempo);
    flores.push_back({x_tallos[i] - tam, x_tallos[i] + tam});
  }

  std::sort(flores.begin(), flores.end());

  int flor_actual = -1;
  int flor_siguiente = 0;
  // Buscamos la primer flor que cubre a la entrada
  while (flor_siguiente < N) {
    if (!(flores[flor_siguiente].first <= x_entrada &&
          x_entrada <= flores[flor_siguiente].second)) {
      ++flor_siguiente;
    } else {
      flor_actual = flor_siguiente;
      break;
    }
  }
  if (flor_actual == -1) {
    // No se cubre el inicio
    return false;
  }
  if (x_salida <= flores[flor_actual].second) {
    // Se alcanzo el final
    return true;
  }

  while (flor_siguiente < N) {
    // Nos movemos a la derecha siempre que podamos
    if (flores[flor_siguiente].first - 1 <= flores[flor_actual].second &&
        flores[flor_actual].second < flores[flor_siguiente].second) {
      flor_actual = flor_siguiente;
    }
    ++flor_siguiente;
  }

  // Checamos si se cubrimos la salida
  return x_salida <= flores[flor_actual].second;
}

int busquedaBinaria() {
  // Binaria sobre el tiempo
  int inicio = 0, final = 2e5 + 10, mitad;

  if (!es_posible(final)) {
    // No se puede llegar a la salida
    return -1;
  }

  while (inicio < final) {
    mitad = (inicio + final) / 2;

    // Vemos si podemos llegar al final si tenemos el tiempo "mitad"
    if (es_posible(mitad)) {
      // Si se puede, probaremos con un tiempo menor
      final = mitad;
    } else {
      // No se puede, probamos con un tiempo mayor
      inicio = mitad + 1;
    }
  }
  return inicio;
}

int main() {
  // Entrada
  std::cin >> N >> M;
  std::cin >> x_entrada >> y_entrada;
  std::cin >> x_salida >> y_salida;

  bool es_subtarea_2 = true;
  int y_valor = y_entrada;
  if (y_valor != y_salida) {
    es_subtarea_2 = false;
  }

  for (int i = 0; i < N; ++i) {
    std::cin >> x_tallos[i] >> y_tallos[i];
    if (y_tallos[i] != y_valor) {
      es_subtarea_2 = false;
    }
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> limite[i];
  }

  if (es_subtarea_2) {
    // Todas las posiciones comparten el valor en y
    // Podemos resolver el subproblema de la subtarea 2
    if (x_entrada > x_salida) {
      // Ordenar salida y entrada
      std::swap(x_entrada, x_salida);
    }
    std::cout << busquedaBinaria() << "\n";
  } else {
    // Resolvemos la subtarea 1

    // Plantear mapa
    for (int i = 0; i < N; ++i) {
      mapa[x_tallos[i]][y_tallos[i]] = 1;
    }

    int tiempo = 0;
    while (!llegamos_al_final()) {
      ++tiempo;
      if (!expandir_flores(tiempo)) {
        // No hubo modificaciones
        tiempo = -1;
        break;
      }
    }
    std::cout << tiempo << "\n";
  }
}
