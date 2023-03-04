#include <iostream>
#include <queue>

typedef std::pair<int, int> pii;

const int MaxN = 510;
const int movs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int mapa[MaxN][MaxN];
bool visitado[MaxN][MaxN];  // True si ya fue procesado, false si no
int historial[MaxN]
             [MaxN];  // -1 si no ha sido visitado, otro numero el paso previo
pii previo[MaxN][MaxN];  // Posicion previa a la actual

void modificarImprimirMatriz(int N, int M) {
  pii posInicial = std::make_pair(N - 1, 0);
  pii posFinal = std::make_pair(0, M - 1);
  while (posInicial != posFinal) {
    // Ver posicion previa al final
    int p = posFinal.first, q = posFinal.second;
    pii posPrev = previo[p][q];
    // Actualizar tablero
    int x = posPrev.first, y = posPrev.second;
    mapa[x][y] = historial[p][q];
    // Mover al previo
    posFinal = posPrev;
  }

  // Imprimir tablero
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cout << mapa[i][j] << " ";
    }
    std::cout << "\n";
  }
}

int main() {
  // Lectura de datos
  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> mapa[i][j];
      historial[i][j] = -1;
    }
  }

  // Queues para la BFS
  std::queue<pii> costoActual;
  std::queue<pii> costoSiguiente;

  // Inicializar
  costoActual.push(std::make_pair(N - 1, 0));
  historial[N - 1][0] = 0;
  int costo = 0;

  // Objetivo
  pii objetivo = std::make_pair(0, M - 1);

  // BFS
  while (!costoActual.empty()) {
    pii posicionActual = costoActual.front();
    costoActual.pop();

    int x = posicionActual.first;
    int y = posicionActual.second;
    if (visitado[x][y]) {
      // Ya fue procesado
      if (costoActual.empty()) {
        ++costo;
        std::swap(costoActual, costoSiguiente);
      }
      continue;
    }
    visitado[x][y] = true;  // Vamos a procesarlo

    if (posicionActual == objetivo) {
      // Objetivo logrado
      std::cout << costo << "\n";
      modificarImprimirMatriz(N, M);
      return 0;
    }

    // Mover estado
    for (int i = 0; i < 4; ++i) {
      // Siguiente posicion
      int p = x + movs[i][0];
      int q = y + movs[i][1];

      if (p < 0 || p == N || q < 0 || q == M) {
        // Posicion invalida
        continue;
      }
      if (visitado[p][q]) {
        // Posicion visitada
        continue;
      }
      if (historial[p][q] != -1 && i != mapa[x][y]) {
        // Ya hay una forma igual o mejor de llegar
        continue;
      }

      // Guarda historial
      historial[p][q] = i;
      previo[p][q] = std::make_pair(x, y);

      // Agrega a queue correspondiente
      if (i == mapa[x][y]) {
        // Sigue el mapa sin modificar
        costoActual.push(std::make_pair(p, q));
      } else {
        // Modifica la posicion (x, y) para moverse a (p, q)
        costoSiguiente.push(std::make_pair(p, q));
      }
    }
    // Aumentar al siguiente nivel si es necesario
    if (costoActual.empty()) {
      ++costo;
      std::swap(costoActual, costoSiguiente);
    }
  }
}
