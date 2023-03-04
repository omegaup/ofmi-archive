#include <iostream>
#include <queue>
#include <vector>

const int maxn = 1000;
enum { libre = 0, pared = -1, cobaya = 1 };

struct posicion {
  int i, j;       // Posición (i, j) en el tablero.
  int distancia;  // Distancia hacia la lechuga.
};

int N, M;
int ncobayas;
int tablero[maxn][maxn];
bool visitado[maxn][maxn];
posicion lechuga;
std::vector<posicion> cobayas;

/**
 * Realizamos una búsqueda en amplitud para calcular la distancia desde la
 * lechuga hacia todas las cobayas. Guarda en un vector la posición y distancia
 * de las cobayas.
 */
void BFS() {
  std::queue<posicion> Q;
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};
  Q.push(lechuga);
  visitado[lechuga.i][lechuga.j] = true;
  while (!Q.empty()) {
    posicion actual = Q.front();
    Q.pop();
    if (tablero[actual.i][actual.j] == cobaya) {
      cobayas.push_back(actual);
    }
    for (int k = 0; k < 4; ++k) {
      posicion siguiente{actual.i + dx[k], actual.j + dy[k],
                         actual.distancia + 1};
      if (0 <= siguiente.i && siguiente.i < N && 0 <= siguiente.j &&
          siguiente.j < M && tablero[siguiente.i][siguiente.j] != pared &&
          !visitado[siguiente.i][siguiente.j]) {
        Q.push(siguiente);
        visitado[siguiente.i][siguiente.j] = true;
      }
    }
  }
}

/**
 * Devuelve el número de cobayas que no pudieron comer la lechuga.
 */
int contarCobayas() {
  int lechuga_restante = tablero[lechuga.i][lechuga.j];
  int i = 0, t = 0;
  while (i < cobayas.size() && lechuga_restante > 0) {
    // Se consume una lechuga por cada cobaya que ya llegó a la lechuga y por
    // cada unidad de tiempo que tardan las demás cobayas en llegar.
    lechuga_restante -= i * (cobayas[i].distancia - t - 1);
    t = cobayas[i].distancia;
    // Todas estas cobayas llegan al mismo tiempo.
    int j = i;
    while (i < cobayas.size() && cobayas[i].distancia == t &&
           lechuga_restante > 0) {
      ++i;
      --lechuga_restante;
    }
    // Las cobayas que ya habían llegado comen después de las que acaban de
    // llegar.
    lechuga_restante -= j;
  }
  return ncobayas - i;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie();
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> tablero[i][j];
      if (tablero[i][j] > cobaya) {
        lechuga = posicion{i, j, 0};
      } else if (tablero[i][j] == cobaya) {
        ++ncobayas;
      }
    }
  }
  BFS();
  std::cout << contarCobayas() << "\n";
  return 0;
}
