#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#include "unodos.h"

typedef std::pair<int, int> pii;

const int MAXN = 100005;
const int MAXM = 200005;

int n, m;
std::vector<pii> adj[MAXN];

bool vis[MAXN];
int valorAsignado[MAXN];
int color[MAXN];  // 1 o -1

bool asignaComponente(int nodo) {
  std::vector<int> componente;
  bool esBipartito = true;
  double x;

  std::queue<int> q;
  vis[nodo] = true;
  valorAsignado[nodo] = 0;
  color[nodo] = 1;
  componente.push_back(nodo);
  q.push(nodo);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    // Nos expandimos a los vecinos
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i].first;
      int sumaEsp = adj[u][i].second;
      if (vis[v]) {
        if (color[u] == color[v]) {
          esBipartito = false;
          x = color[v] * (sumaEsp - valorAsignado[v] - valorAsignado[u]) / 2;
        }
        continue;
      }
      vis[v] = true;
      color[v] = -color[u];
      valorAsignado[v] = sumaEsp - valorAsignado[u];
      componente.push_back(v);
      q.push(v);
    }
  }

  if (esBipartito) {
    std::vector<int> num(componente.size());
    for (int i = 0; i < componente.size(); i++) {
      int nodo = componente[i];
      num[i] = (-color[nodo]) * valorAsignado[nodo];
    }
    std::sort(num.begin(), num.end());
    x = num[num.size() / 2];
  }

  // Asignamos
  for (int i = 0; i < componente.size(); i++) {
    int nodo = componente[i];
    valorAsignado[nodo] += color[nodo] * x;
    asigna(nodo, 0.5 * (double)(valorAsignado[nodo]));
  }

  // Checamos que después de la asignación todas las aristas
  // cumplan con la restricción
  for (int i = 0; i < componente.size(); i++) {
    int u = componente[i];
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      int sumaEsp = adj[u][j].second;
      if (valorAsignado[u] + valorAsignado[v] != sumaEsp) {
        return false;
      }
    }
  }

  return true;
}

bool unoDos(int n, int m, int U[], int V[], int T[]) {
  for (int i = 0; i < m; i++) {
    adj[U[i]].push_back({V[i], 2 * T[i]});
    adj[V[i]].push_back({U[i], 2 * T[i]});
  }

  bool posible = true;
  for (int u = 1; u <= n; u++) {
    if (!vis[u]) {
      posible &= asignaComponente(u);
    }
  }

  return posible;
}
