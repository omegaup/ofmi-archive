#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100000
#define ll long long

int n, m;
int x, y, z;

std::vector<std::vector<int> > E;  // Lista de adyacencia.

// Hace una BFS partiendo del nodo s para calcular el camino mínimo entre s y t.
int distanciaMinima(int s, int t) {
  // Inicialización: visitar estado inicial y meterlo a la cola.
  std::vector<int> vis(n + 1, -1);
  vis[s] = 0;
  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    // Mientras la cola no esté vacía, procesamos el nodo al frente de la cola.
    int nodo_act = q.front();
    q.pop();

    if (nodo_act == t) {
      return vis[t];
    }

    // Transiciones: revisamos todos los vecinos del nodo actual.
    for (int i = 0; i < E[nodo_act].size(); i++) {
      int vecino = E[nodo_act][i];

      if (vis[vecino] == -1) {
        // Si el vecino no está visitado, lo procesamos:
        // Visitamos, guardamos la distancia mínima y agregamos a la cola.
        vis[vecino] = vis[nodo_act] + 1;
        q.push(vecino);
      }
    }
  }

  return vis[t];
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  std::cin >> n >> m;
  std::cin >> x >> y >> z;

  // Indicamos el tamaño para la lista de adyacencia y los arreglos dis.
  E.resize(n + 1);

  // Leemos las aristas y las agregamos a las listas de adyacencia adecuada.
  int u, v;
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  // La primera opción es que cada persona vaya a N por su cuenta.
  ll res =
      (ll)x * (ll)distanciaMinima(1, n) + (ll)y * (ll)distanciaMinima(2, n);

  // Además, pueden elegir algun punto de encuentro 'p', 1 <= p < N, viajar
  // cada una por su cuenta a 'p' y luego desde 'p' viajar juntas a N.
  for (int p = 1; p < n; p++) {
    ll dis = (ll)x * (ll)distanciaMinima(1, p) +
             (ll)y * (ll)distanciaMinima(2, p) + (ll)z * distanciaMinima(p, n);
    res = std::min(res, dis);
  }

  std::cout << res << "\n";
  return 0;
}