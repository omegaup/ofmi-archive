#include <iostream>
#include <queue>
#include <vector>

#include "viajecobayas.h"

int _movs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
std::vector<std::pair<int, int>> colors[200 * 200 + 1];

int myViajeCobayas(int N, int M, int matriz[][200], int r1, int c1, int r2,
                   int c2) {
  // BFS - Definir conexiones
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      if (matriz[i][j] == -1) {
        continue;
      }
      colors[matriz[i][j]].push_back({i, j});
    }

  // BFS - Declarar visitados
  bool vis[N][M];
  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j) {
      vis[i][j] = false;
    }

  // BFS - Inicializacion
  std::queue<std::pair<int, std::pair<int, int>>> bsq;
  bsq.push({0, {r1, c1}});  // Indexar en 0
  vis[r1][c1] = true;

  // BFS - Busqueda
  while (!bsq.empty()) {
    auto state = bsq.front();
    bsq.pop();
    int t = state.first;
    int x = state.second.first;
    int y = state.second.second;

    // Checar meta
    if (x == r2 && y == c2) {  // Checar index en 0
      return t;
    }

    // Adyacentes
    for (int i = 0; i < 4; ++i) {
      int x_next = x + _movs[i][0];
      int y_next = y + _movs[i][1];
      if (x_next < 0 || x_next == N || y_next < 0 || y_next == M) {
        continue;
      }
      if (vis[x_next][y_next] || matriz[x_next][y_next] == -1) {
        continue;
      }
      vis[x_next][y_next] = true;
      bsq.push({t + 1, {x_next, y_next}});
    }
    // Conectados
    for (auto color : colors[matriz[x][y]]) {
      int x_next = color.first;
      int y_next = color.second;
      if (vis[x_next][y_next]) {
        continue;
      }
      vis[x_next][y_next] = true;
      bsq.push({t + 1, {x_next, y_next}});
    }
    colors[matriz[x][y]].clear();
  }
  // No se pudo llegar
  return -1;
}

int matriz[200][200];

int main() {
  int N, M;
  std::cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      std::cin >> matriz[i][j];
    }
  }
  int r1, c1, r2, c2;
  std::cin >> r1 >> c1;
  std::cin >> r2 >> c2;
  int expected = myViajeCobayas(N, M, matriz, r1, c1, r2, c2);
  int obtained = viajeCobayas(N, M, matriz, r1, c1, r2, c2);

  if (obtained != expected) {
    // Hay error, hay error
    fprintf(stderr, "Got %d, expected %d", obtained, expected);
    printf("0.00\n");
  } else {
    fprintf(stderr, "Correct answer");
    printf("1.00\n");
  }
  return 0;
}
