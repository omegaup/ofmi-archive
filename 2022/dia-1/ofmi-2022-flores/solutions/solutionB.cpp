#include <iostream>
#include <vector>
#define pb push_back
#define ENTRADA 0
#define SALIDA 1
#define ceil(a, b) (a / (b) + !!(a % (b)))
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fore(i, a, b) for (int i = int(a); i < int(b); i++)

struct pii {
  int tiempo, nodo;
};

struct Flor {
  int x, y, limite;
};

int n, m;
std::vector<std::vector<pii>> grafo;
std::vector<bool> visitado;

bool dfs(int nodo, int tiempo) {
  bool encontrado = nodo == SALIDA;
  visitado[nodo] = true;

  for (pii vecino : grafo[nodo]) {
    if (!visitado[vecino.nodo] && vecino.tiempo <= tiempo) {
      encontrado |= dfs(vecino.nodo, tiempo);
    }
  }

  return encontrado;
}

int calcula_interseccion(Flor a, Flor b) {
  // TODO: probar a == b => 0
  if (m == 0) return -1;

  int dis = std::max(abs(a.x - b.x), abs(a.y - b.y));
  int limite_menor = std::min(a.limite != -1 ? a.limite : m * ceil(dis, m),
                              b.limite != -1 ? b.limite : m * ceil(dis, m));
  int limite_mayor = std::max(a.limite != -1 ? a.limite : m * ceil(dis, m),
                              b.limite != -1 ? b.limite : m * ceil(dis, m));

  if (dis - limite_menor - limite_mayor <= 0) {
    int t = ceil(limite_menor, m);
    if (dis - limite_menor - std::min(t * m, limite_mayor) > 0) {
      dis = dis - limite_menor - std::min(t * m, limite_mayor);
      return t + ceil(dis, m);
    } else {
      return ceil(dis, 2 * m);
    }
  } else {
    return -1;
  }
}

int main() {
  std::cin >> n >> m;
  n += 2;
  std::vector<Flor> flores(n);
  for (auto &[x, y, _] : flores) std::cin >> x >> y;
  fore(i, 2, n) { std::cin >> flores[i].limite; }

  grafo = std::vector<std::vector<pii>>(n);
  forn(i, n) {
    fore(j, i + 1, n) {
      int momento_interseccion = calcula_interseccion(flores[i], flores[j]);
      if (momento_interseccion != -1) {
        grafo[i].pb({momento_interseccion, j});
        grafo[j].pb({momento_interseccion, i});
      }
    }
  }

  // Búsqueda binaria
  int limite_inferior = 0, limite_superior = 2e5 + 10;
  while (limite_inferior < limite_superior) {
    int mitad = (limite_inferior + limite_superior) / 2;
    visitado = std::vector<bool>(n, 0);
    if (dfs(ENTRADA, mitad))
      limite_superior = mitad;
    else
      limite_inferior = mitad + 1;
  }

  if (limite_inferior == 2e5 + 10) {
    std::cout << "-1\n";
  } else {
    std::cout << limite_inferior << "\n";
  }
  return 0;
}
