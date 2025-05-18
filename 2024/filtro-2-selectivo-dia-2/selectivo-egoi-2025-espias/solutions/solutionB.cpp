#include <iostream>
#include <stack>
#include <vector>

const int MaxN = 1000005;

std::vector<int> vis(MaxN);
std::vector<int> cant(MaxN);
std::vector<int> voyA(MaxN);

void rellenaCiclo(int espia) {
  std::stack<int> pila;
  pila.push(espia);
  int tam = 0;

  while (!pila.empty()) {
    int actual = pila.top();

    if (vis[actual] == 2) {
      break;
    }
    vis[actual] = 2;
    tam++;

    int siguiente = voyA[actual];
    pila.push(siguiente);
  }

  while (!pila.empty()) {
    int actual = pila.top();
    pila.pop();

    cant[actual] = tam;
  }
}

void dfs(int espia) {
  std::stack<int> pila;
  pila.push(espia);

  while (!pila.empty()) {
    int actual = pila.top();

    if (vis[actual] == 2) {
      pila.pop();
      break;
    }
    if (vis[actual] == 1) {
      rellenaCiclo(actual);
      break;
    }
    vis[actual] = 1;

    int siguiente = voyA[actual];
    pila.push(siguiente);
  }

  while (!pila.empty()) {
    int actual = pila.top();
    pila.pop();

    if (vis[actual] == 2) {
      continue;
    }
    vis[actual] = 2;
    cant[actual] = cant[voyA[actual]] + 1;
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  for (int i = 1; i <= n; i++) {
    int espia;
    std::cin >> espia;
    voyA[i] = espia;
  }

  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) dfs(i);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, cant[i]);
  }
  std::cout << ans << "\n";
}
