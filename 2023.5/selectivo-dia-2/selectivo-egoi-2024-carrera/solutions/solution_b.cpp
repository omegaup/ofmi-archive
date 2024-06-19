#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

struct Coche {
  // Los coches se ordenan por posicion inicial.
  bool operator<(const Coche& otro) const { return x < otro.x; }

  int x, v, id, lugar;
};

struct MomentoClave {
  bool operator<(const MomentoClave& otro) const {
    if (tiempo != otro.tiempo) return tiempo < otro.tiempo;

    // Si dos momentos clave ocurren al mismo tiempo, reportamos primero el que
    // sucede mas a la izquierda; guardamos un apuntador al coche que va a
    // adelantar para poder calcular donde sucedera el adelanto.
    return coche->x + tiempo * coche->v <
           otro.coche->x + tiempo * otro.coche->v;
  }

  Coche* coche;
  double tiempo;
};

int main() {
  std::cin.tie(nullptr);
  std::ios_base::sync_with_stdio(false);

  int n, m;
  std::cin >> n >> m;

  std::vector<Coche> coches(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> coches[i].x >> coches[i].v;
    coches[i].id = i + 1;
  }

  // Ordenamos los coches.
  std::sort(coches.begin(), coches.end());

  // Mas adelante requeriremos algunos `swap` para mantener los coches en orden,
  // esto no se puede hacer en el arreglo original, ya que invalidaria los
  // apuntadores que vamos a guardar dentro de los momentos clave.
  std::vector<Coche*> lista_coches(n);
  for (int i = 0; i < n; ++i) {
    coches[i].lugar = i;
    lista_coches[i] = &coches[i];
  }

  auto TiempoParaAdelantar = [&](int i) -> double {
    double dv = lista_coches[i - 1]->v - lista_coches[i]->v;
    return (lista_coches[i]->x - lista_coches[i - 1]->x) / dv;
  };

  // Guardamos los momentos clave en un set para evitar duplicados.
  std::set<MomentoClave> momentos;

  for (int i = 1; i < n; ++i) {
    // El coche `i - 1` adelanta al coche `i` si su velocidad es mayor.
    if (lista_coches[i - 1]->v > lista_coches[i]->v)
      momentos.insert({lista_coches[i - 1], TiempoParaAdelantar(i)});
  }

  while (m--) {
    Coche& coche_veloz = *momentos.begin()->coche;
    momentos.erase(momentos.begin());

    Coche& coche_lento = *lista_coches[coche_veloz.lugar + 1];
    std::cout << coche_veloz.id << ' ' << coche_lento.id << '\n';

    std::swap(lista_coches[coche_veloz.lugar], lista_coches[coche_lento.lugar]);
    std::swap(coche_veloz.lugar, coche_lento.lugar);

    if (coche_veloz.lugar + 1 < n &&
        coche_veloz.v > lista_coches[coche_veloz.lugar + 1]->v) {
      momentos.insert(
          {&coche_veloz, TiempoParaAdelantar(coche_veloz.lugar + 1)});
    }

    if (coche_lento.lugar &&
        lista_coches[coche_lento.lugar - 1]->v > coche_lento.v) {
      momentos.insert({lista_coches[coche_lento.lugar - 1],
                       TiempoParaAdelantar(coche_lento.lugar)});
    }
  }
  return 0;
}
