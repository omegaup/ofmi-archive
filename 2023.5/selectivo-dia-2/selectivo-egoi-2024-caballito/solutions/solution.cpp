#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#define MAX_N 100000
#define ll long long

int n, m;
int x, y, z;

std::vector<std::vector<int> > E;  // Lista de adyacencia.
bool vis[MAX_N + 2];               // Arreglo para marcar visitados en la BFS.
std::vector<int> disA, disB,
    disN;  // Arreglos para guardar las distancias minimas calculadas en la BFS.

// Hace una BFS partiendo del nodo s para almacenar la distancia mínima
// del nodo s a todos los nodos del grafo. Las distancias mínimas se guardan
// en el arreglo que se pasa por referencia, dis.
void distanciaMinima(int s, std::vector<int>& dis) {
  // Inicialización: visitar estado inicial y meterlo a la cola.
  std::fill(vis, vis + n + 1, 0);
  vis[s] = true;
  dis[s] = 0;
  std::queue<int> q;
  q.push(s);

  while (!q.empty()) {
    // Mientras la cola no esté vacía, procesamos el nodo al frente de la cola.
    int nodo_act = q.front();
    q.pop();

    // Transiciones: revisamos todos los vecinos del nodo actual.
    for (int i = 0; i < E[nodo_act].size(); i++) {
      int vecino = E[nodo_act][i];

      if (!vis[vecino]) {
        // Si el vecino no está visitado, lo procesamos:
        // Visitamos, guardamos la distancia mínima y agregamos a la cola.
        vis[vecino] = true;
        dis[vecino] = dis[nodo_act] + 1;
        q.push(vecino);
      }
    }
  }
}

int main() {
  std::cin >> n >> m;
  std::cin >> x >> y >> z;

  // Indicamos el tamaño para la lista de adyacencia y los arreglos dis.
  E.resize(n + 1);
  disA.resize(n + 1);
  disB.resize(n + 1);
  disN.resize(n + 1);

  // Leemos las aristas y las agregamos a las listas de adyacencia adecuada.
  int u, v;
  for (int i = 0; i < m; i++) {
    std::cin >> u >> v;
    E[u].push_back(v);
    E[v].push_back(u);
  }

  // Hacemos una BFS iniciando en los nodos 1, 2 y N. En los respectivos
  // Arreglos disA, disB, disN quedarán guardadas las distancias mínimas
  // entre dichos nodos y todos los nodos del arreglo.
  distanciaMinima(1, disA);
  distanciaMinima(2, disB);
  distanciaMinima(n, disN);

  // La primera opción es que cada persona vaya a N por su cuenta.
  ll res = (ll)x * (ll)disA[n] + (ll)y * (ll)disB[n];

  // Además, pueden elegir algun punto de encuentro 'p', 1 <= p < N, viajar
  // cada una por su cuenta a 'p' y luego desde 'p' viajar juntas a N.
  for (int p = 1; p < n; p++) {
    ll dis = (ll)x * (ll)disA[p] + (ll)y * (ll)disB[p] + (ll)z * disN[p];
    res = std::min(res, dis);
  }

  std::cout << res << "\n";
  return 0;
}