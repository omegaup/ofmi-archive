#include <iostream>
#include <utility>
#include <vector>

const int MaxN = 10005;

int n, m;
std::vector<std::pair<int, int> > ady[MaxN];
std::vector<bool> visitado(MaxN);
int globalAns = 11;

int calculaSuma(int bitmask) {
  int tot = 0;
  while (bitmask > 0) {
    tot += bitmask & 1;
    bitmask = bitmask >> 1;
  }
  return tot;
}

void dfs(int nodo, const int bitmask) {
  if (visitado[nodo]) return;
  visitado[nodo] = 1;

  if (nodo == n) {
    globalAns = std::min(globalAns, calculaSuma(bitmask));
    return;
  }

  for (auto siguiente : ady[nodo]) {
    int nodoSig = siguiente.first;
    int valor = siguiente.second;

    if (!((1 << valor) & bitmask)) continue;
    dfs(nodoSig, bitmask);
  }
}

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  std::cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int p, q, x;
    std::cin >> p >> q >> x;
    ady[p].push_back({q, --x});
    ady[q].push_back({p, x});
  }

  for (int i = 0; i < (1 << 10); i++) {
    if (calculaSuma(i) > globalAns) continue;

    std::fill(visitado.begin(), visitado.end(), false);
    dfs(1, i);
  }
  std::cout << (globalAns != 11 ? globalAns : -1) << "\n";
}
