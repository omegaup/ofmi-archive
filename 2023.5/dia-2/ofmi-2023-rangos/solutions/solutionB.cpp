#include <algorithm>
#include <iostream>
#include <set>
#include <utility>

typedef std::pair<int, int> pii;
const int MAXN = 100002;

int n;
pii P[MAXN];                       // first->posicion, second->indice
std::pair<pii, int> rangos[MAXN];  // first->inicio, second->fin, third->indice

int ans[MAXN];  // ans[i] te dice el indice de la medición que le corresponde al

int main() {
  // Leemos la entrada
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> P[i].first;
    P[i].second = i;
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> rangos[i].first.first >> rangos[i].first.second;
    rangos[i].second = i;
  }

  // IDEA.
  // Para cada rango le vamos a asignar la medición que termina primero
  // que no haya sido asignada que este en el rango

  // Creamos un set de las mediciones que no han sido asignados
  std::set<pii> S;
  for (int i = 0; i < n; ++i) {
    S.insert(P[i]);
  }

  // Ordenamos los rangos por el que termina primero
  std::sort(rangos, rangos + n,
            [](const std::pair<pii, int>& a, const std::pair<pii, int>& b) {
              return a.first.second < b.first.second;
            });

  // Para cada rango
  bool imposible = false;
  for (int i = 0; i < n; ++i) {
    int l = rangos[i].first.first;
    int r = rangos[i].first.second;

    // Buscamos la primer medición que esté en el rango
    // y que no haya sido asignada
    auto it = S.lower_bound({l, -1});
    if (it == S.end() || it->first > r) {
      // Es imposible asignarle una medición
      imposible = true;
      break;
    }
    ans[rangos[i].second] = it->second;
    S.erase(it);
  }

  if (imposible) {
    std::cout << "-1\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << " \n"[i == (n - 1)];
  }

  return 0;
}
