#include <algorithm>
#include <iostream>
#include <queue>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include "unodos.h"

typedef std::pair<int, int> pii;

int getSubtask(const std::string& caseName) {
  std::regex pattern(".*sub(\\d+).*");
  std::smatch match;
  if (std::regex_search(caseName, match, pattern)) {
    std::string caseNumber = match[1];
    return std::stoi(caseNumber);
  }
  return -1;
}

const double EPS = 1e-6;

const int MAXN = 100002;
const int MAXM = 200002;
int n, m;

int U[MAXM], V[MAXM], T[MAXM];
bool asignado[MAXN];
double valorAsignado[MAXN];

bool asignado_correctamente = true;
int num_asignados = 0;
double sumaValoresAbsolutos = 0.0;
bool asigna(int v, double x) {
  if (v <= 0 || v > n) {
    asignado_correctamente = false;
    return false;
  }
  if (asignado[v]) {
    asignado_correctamente = false;
    return false;
  }
  num_asignados++;
  asignado[v] = true;
  valorAsignado[v] = x;
  sumaValoresAbsolutos += std::abs(x);
  return true;
}

bool is_equal(double r, double s) { return std::abs(r - s) <= EPS; }

std::vector<pii> adj[MAXN];
bool vis[MAXN];
int valorAsignadoOficial[MAXN];
int color[MAXN];  // 1 o -1
double ansOficial = 0.0;
bool asignaComponente(int nodo) {
  std::vector<int> componente;
  bool esBipartito = true;
  double x;

  std::queue<int> q;
  vis[nodo] = true;
  valorAsignadoOficial[nodo] = 0;
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
          x = color[v] *
              (sumaEsp - valorAsignadoOficial[v] - valorAsignadoOficial[u]) / 2;
        }
        continue;
      }
      vis[v] = true;
      color[v] = -color[u];
      valorAsignadoOficial[v] = sumaEsp - valorAsignadoOficial[u];
      componente.push_back(v);
      q.push(v);
    }
  }

  if (esBipartito) {
    std::vector<int> num(componente.size());
    for (int i = 0; i < componente.size(); i++) {
      int nodo = componente[i];
      num[i] = (-color[nodo]) * valorAsignadoOficial[nodo];
    }
    std::sort(num.begin(), num.end());
    x = num[num.size() / 2];
  }

  // Asignamos
  for (int i = 0; i < componente.size(); i++) {
    int nodo = componente[i];
    valorAsignadoOficial[nodo] += color[nodo] * x;
    ansOficial += 0.5 * (double)(std::abs(valorAsignadoOficial[nodo]));
  }

  // Checamos que después de la asignación todas las aristas
  // cumplan con la restricción
  for (int i = 0; i < componente.size(); i++) {
    int u = componente[i];
    for (int j = 0; j < adj[u].size(); j++) {
      int v = adj[u][j].first;
      int sumaEsp = adj[u][j].second;
      if (valorAsignadoOficial[u] + valorAsignadoOficial[v] != sumaEsp) {
        return false;
      }
    }
  }

  return true;
}

bool unoDosOficial(int n, int m, int U[], int V[], int T[]) {
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

int subtask;
double respuestaCorrecta(bool posible) {
  // Llamamos a la respuesta oficial
  bool posibleOficial = unoDosOficial(n, m, U, V, T);
  if (posible != posibleOficial) {
    return false;
  }
  if (!posible) {
    return true;
  }
  // Checamos que hayamos asignado correctamente valor a todos los nodos
  if (num_asignados < n || !asignado_correctamente) {
    return false;
  }
  // Checamos que todas las aristas cumplan con la condicion
  for (int i = 0; i < m; ++i) {
    double sumaArista = valorAsignado[U[i]] + valorAsignado[V[i]];
    if (T[i] == 1) {
      if (!is_equal(sumaArista, 1.0)) {
        return false;
      }
    } else {
      if (!is_equal(sumaArista, 2.0)) {
        return false;
      }
    }
  }
  if (subtask == 2 || subtask == 3) {
    // El evaluador no tomará en cuenta el valor de la suma
    return true;
  }
  return is_equal(ansOficial, sumaValoresAbsolutos);
}

int main(int argc, char* argv[]) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  // Obtenemos el nombre del caso
  std::string caseName = argv[1];
  std::cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    std::cin >> U[i] >> V[i] >> T[i];
  }
  // Llamamos a la función de la participante
  bool posible = unoDos(n, m, U, V, T);

  // Checamos que la respuesta sea correcta
  subtask = getSubtask(caseName);
  if (respuestaCorrecta(posible)) {
    std::cout << 1.0 << std::endl;
  } else {
    std::cout << 0.0 << std::endl;
  }

  return 0;
}
