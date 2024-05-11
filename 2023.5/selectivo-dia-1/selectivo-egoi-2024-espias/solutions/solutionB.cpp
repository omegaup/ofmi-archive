#include <bitset>
#include <functional>
#include <iostream>

const int MAXN = 1e6;

struct Stack {
  int st[MAXN + 1];
  int sz;
  Stack() : sz(0) {}
  int top() { return st[sz - 1]; }
  void push(int x) { st[sz++] = x; }
  void pop() { sz--; }
};

struct Scc {
  int n, cmpCnt;
  int graph[MAXN + 1];
  int tin[MAXN + 1], low[MAXN + 1], comp[MAXN + 1];
  int indegree[MAXN + 1];
  std::bitset<MAXN + 1> inStack;
  Stack st;
  int solve() {
    int timer = 0;
    cmpCnt = 0;
    std::function<void(int)> dfs = [&](int v) {
      tin[v] = low[v] = ++timer;
      inStack[v] = 1;
      st.push(v);
      int u = graph[v];
      if (!tin[u]) {
        dfs(u);
        low[v] = std::min(low[v], low[u]);
      } else if (inStack[u]) {
        low[v] = std::min(low[v], tin[u]);
      }

      if (tin[v] == low[v]) {
        u = v;
        cmpCnt++;
        do {
          comp[u] = cmpCnt;
          inStack[u] = 0;
          u = st.top();
          st.pop();
        } while (u != v);
      }
    };
    for (int i = 1; i <= n; i++)
      if (comp[i] == 0) dfs(i);
    for (int i = 1; i <= n; i++) {
      if (comp[i] != comp[graph[i]]) {
        indegree[comp[graph[i]]]++;
      }
    }
    int res = 0;
    for (int i = 1; i <= cmpCnt; i++) {
      res += indegree[i] == 0;
    }
    return res;
  }
};
Scc sp;

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);

  std::cin >> sp.n;
  for (int i = 1; i <= sp.n; i++) {
    std::cin >> sp.graph[i];
  }
  std::cout << sp.solve();
  return 0;
}