#include <algorithm>
#include <cstdint>
#include <iostream>
#include <queue>
#include <vector>
typedef long long lld;

struct Coche {
  lld x, v;
  int id;
};

typedef Coche* CochePtr;

struct ComparaMomentos {
  bool operator()(const std::pair<CochePtr, CochePtr>& a,
                  const std::pair<CochePtr, CochePtr>& b) {
    // Regresa true si el coche b->first alcanza al coche b->second
    // antes que el coche a->first alcance al coche a->second
    // Esto es porque el prioriry queue es un max heap
    std::uint64_t dxA = a.second->x - a.first->x;
    std::uint64_t dvA = a.first->v - a.second->v;
    std::uint64_t dxB = b.second->x - b.first->x;
    std::uint64_t dvB = b.first->v - b.second->v;
    if (dxB * dvA == dxA * dvB) {
      return (b.first->x * dvB + b.first->v * dxB) * dvA <
             (a.first->x * dvA + a.first->v * dxA) * dvB;
    }
    return dxB * dvA < dxA * dvB;
  }
};

bool seraMomentoClave(const CochePtr& a, const CochePtr& b) {
  // Regresa true si la coche A alcanzará al coche B en algún momento
  return a->x < b->x && a->v > b->v;
}

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;
  // Leemos la información de los n coches
  std::vector<CochePtr> Coches(n, NULL);
  for (int i = 0; i < n; i++) {
    Coches[i] = new Coche();
    std::cin >> Coches[i]->x >> Coches[i]->v;
    Coches[i]->id = i + 1;
  }
  // Ordenamos las Coches por su posición
  std::sort(Coches.begin(), Coches.end(),
            [](const CochePtr& a, const CochePtr& b) { return a->x < b->x; });

  /* Si mantenemos los coches por su posición, sabemos que solo
      puede ocurrir que el i-ésimo momento clave sea algun coche en
      el índice j con el coche en el índice j + 1.

      Por lo que podemos mantener una priority queue que compare
      el primer momento en el que la coche j alcanza al coche j + 1
      para toda j.
  */

  std::priority_queue<std::pair<CochePtr, CochePtr>,
                      std::vector<std::pair<CochePtr, CochePtr> >,
                      ComparaMomentos>
      pq;
  std::vector<int> p(n + 1, 0);  // En qué indice está la coche con id i
  for (int i = 0; i < n; i++) {
    p[Coches[i]->id] = i;
    if (i > 0 && seraMomentoClave(Coches[i - 1], Coches[i])) {
      pq.push({Coches[i - 1], Coches[i]});
    }
  }

  // Simulamos los m momentos
  for (int i = 0; i < m;) {
    // Obtenemos el momento clave
    auto momento = pq.top();
    pq.pop();
    // Checamos que ese momento clave siga siendo válido
    auto CocheA = momento.first;
    auto CocheB = momento.second;
    int posA = p[momento.first->id];   // Posicion del coche A
    int posB = p[momento.second->id];  // Posicion del coche B
    if (Coches[posA]->id != CocheA->id || Coches[posB]->id != CocheB->id ||
        posA + 1 != posB) {
      continue;
    }
    // Imprimimor el momento clave
    std::cout << CocheA->id << " " << CocheB->id << std::endl;
    // Intercambiamos los coches y actualizamos indices
    std::swap(Coches[posA], Coches[posB]);
    std::swap(p[CocheA->id], p[CocheB->id]);
    // Agrergamos los nuevos momentos clave
    if (posA > 0 && seraMomentoClave(Coches[posA - 1], Coches[posA])) {
      pq.push({Coches[posA - 1], Coches[posA]});
    }
    if (posB + 1 < n && seraMomentoClave(Coches[posB], Coches[posB + 1])) {
      pq.push({Coches[posB], Coches[posB + 1]});
    }

    i++;
  }

  return 0;
}
