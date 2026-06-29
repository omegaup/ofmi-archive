#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

struct Cambio {
  bool operator<(Cambio otro) const { return posicion < otro.posicion; }

  bool inicio;
  int posicion;
  int energia;
};

struct Intervalo {
  int energia;
  int tamanio;
};

struct Query {
  bool operator<(Query otra) const { return x < otra.x; }

  int idx;
  int x;
};

struct Respuesta {
  bool operator<(Respuesta otra) const { return idx < otra.idx; }

  int idx;
  int respuesta;
};

int main() {
  int n, k;
  std ::cin >> n >> k;
  std ::vector<Cambio> marcas;

  marcas.push_back({true, 1, 0});
  marcas.push_back({false, n + 1, 0});

  for (int i = 0; i < k; i++) {
    int l, r, e;
    std ::cin >> l >> r >> e;

    marcas.push_back({true, l, e});
    marcas.push_back({false, r + 1, e});
  }

  sort(marcas.begin(), marcas.end());

  int marca_anterior = 1;
  int energia_actual = 0;

  std ::map<int, int> sectores_por_energia;

  for (auto marca : marcas) {
    int posicion_actual = marca.posicion;
    int longitud = posicion_actual - marca_anterior;
    sectores_por_energia[energia_actual] += longitud;

    if (marca.inicio) {
      energia_actual += marca.energia;
    } else {
      energia_actual -= marca.energia;
    }

    marca_anterior = marca.posicion;
  }

  int q;
  std ::cin >> q;
  std ::vector<Query> querys;
  std ::vector<Respuesta> respuesta;
  int sectores = 0;

  for (int i = 0; i < q; i++) {
    int x;
    std ::cin >> x;
    querys.push_back({i, x});
  }

  sort(querys.begin(), querys.end());

  int i = 0;
  for (auto sector : sectores_por_energia) {
    while (i < q and querys[i].x <= sector.first) {
      respuesta.push_back({querys[i].idx, sectores});
      i++;
    }

    sectores += sector.second;
  }

  while (i < q) {
    respuesta.push_back({querys[i].idx, sectores});
    i++;
  }

  sort(respuesta.begin(), respuesta.end());

  for (auto r : respuesta) {
    std ::cout << n - r.respuesta << "\n";
  }
}
