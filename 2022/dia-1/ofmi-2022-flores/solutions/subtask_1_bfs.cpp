#include <iostream>
#include <queue>

const int MaxN = 110;

int movs[8][2] = {{1, 1},  {1, 0},  {1, -1}, {0, 1},
                  {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};
int mapa[MaxN][MaxN];
bool visitados[MaxN][MaxN];

int N, M;
int x_entrada, y_entrada;
int x_salida, y_salida;
int x_tallos[MaxN], y_tallos[MaxN];
int limite[MaxN];

bool expandir_flores(int tiempo) {
  bool modificacion = false;
  // Trazar cada flor
  for (int i = 0; i < N; ++i) {
    // Expansion de la flor
    int tam_flor = std::min(limite[i], M * tiempo);
    if (tam_flor == -1) {
      tam_flor = M * tiempo;
    }
    int minX = std::max(x_tallos[i] - tam_flor, 0);
    int maxX = std::min(x_tallos[i] + tam_flor, MaxN - 1);
    int minY = std::max(y_tallos[i] - tam_flor, 0);
    int maxY = std::min(y_tallos[i] + tam_flor, MaxN - 1);

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

int main() {
  // Entrada
  std::cin >> N >> M;
  std::cin >> x_entrada >> y_entrada;
  std::cin >> x_salida >> y_salida;

  for (int i = 0; i < N; ++i) {
    std::cin >> x_tallos[i] >> y_tallos[i];
  }
  for (int i = 0; i < N; ++i) {
    std::cin >> limite[i];
  }

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
