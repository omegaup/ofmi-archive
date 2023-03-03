#include <array>
#include <iostream>
#include <set>

const int MAX = 510;
int inf = 1e9;
int n, m, mdo[MAX][MAX], d[MAX][MAX];
int who[MAX][MAX];

int dc[] = {0, 1, 0, -1};
int df[] = {-1, 0, 1, 0};

void generaRespuesta() {
  int f = 0, c = m - 1;
  while (f != n - 1 || c != 0) {
    int dir = who[f][c];
    int dir_contraria = (dir + 2) % 4;

    int ff = f + df[dir_contraria], cc = c + dc[dir_contraria];
    mdo[ff][cc] = dir;

    f = ff;
    c = cc;
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      std::cin >> mdo[i][j];
      d[i][j] = inf;
    }
  d[n - 1][0] = 0;

  /*
   {costo, fila, columna}
  */
  std::set<std::array<int, 3> > pq;

  // Empieza en la esquina inferior izquierda con costo 0, la direccion de donde
  // viene no se ocupara
  pq.insert({0, n - 1, 0});

  while (!pq.empty()) {
    auto curr = *pq.begin();
    pq.erase(pq.begin());

    int costo = curr[0];
    int f = curr[1];
    int c = curr[2];

    if (f == 0 && c == m - 1) {
      std::cout << costo << "\n";
      generaRespuesta();
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) std::cout << mdo[i][j] << " ";
        std::cout << "\n";
      }
      return 0;
    }

    for (int dir = 0; dir < 4; dir++) {
      int ff = f + df[dir], cc = c + dc[dir];
      int nuevo_costo = costo + (dir != mdo[f][c]);
      if (ff < 0 || ff >= n || cc < 0 || cc >= m || nuevo_costo >= d[ff][cc])
        continue;
      pq.erase({d[ff][cc], ff, cc});
      d[ff][cc] = nuevo_costo;
      who[ff][cc] = dir;
      pq.insert({d[ff][cc], ff, cc});
    }
  }

  return 0;
}
