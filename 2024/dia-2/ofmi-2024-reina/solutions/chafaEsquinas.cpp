#include <cmath>
#include <iostream>
#include <vector>

struct Coordenada {
  bool operator==(const Coordenada& otra) const {
    return x == otra.x && y == otra.y;
  }

  bool operator!=(const Coordenada& otra) const {
    return x != otra.x || y != otra.y;
  }

  int x, y;
};

struct Tablero {
  std::vector<Coordenada> caballos;
  std::vector<Coordenada> alfiles;
  std::vector<Coordenada> torres;

  int n;
  Coordenada reina;

  std::vector<Coordenada> movimientosCaballo;
  std::vector<Coordenada> posiciones;

  Tablero(int N, int x, int y) : n(N), reina{x, y} {
    movimientosCaballo = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1},
                          {2, 1},   {1, 2},   {-1, 2}, {-2, 1}};

    if (reina.y != 1) posiciones.push_back({reina.x, 1});
    if (reina.y != n) posiciones.push_back({reina.x, n});
    if (reina.x != 1) posiciones.push_back({1, reina.y});
    if (reina.x != n) posiciones.push_back({n, reina.y});

    Coordenada nueva;

    nueva = {1, reina.y + (reina.x - 1)};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {reina.x - (n - reina.y), n};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {reina.y + (reina.x - 1), 1};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {n, reina.y - (n - reina.x)};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);

    nueva = {reina.x - (reina.y - 1), 1};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {1, reina.y - (reina.x - 1)};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {n, reina.y + (n - reina.x)};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
    nueva = {reina.x + (n - reina.y), n};
    if (coordenadaValida(nueva) && reina != nueva) posiciones.push_back(nueva);
  }

  bool coordenadaValida(const Coordenada& c) const {
    return c.x > 0 && c.x <= n && c.y > 0 && c.y <= n;
  }

  bool caballoAtaca(const Coordenada& curr) const {
    for (const auto& caballo : caballos) {
      for (const auto& p : movimientosCaballo) {
        if (Coordenada{p.x + caballo.x, p.y + caballo.y} == curr) return true;
      }
    }
    return false;
  }

  bool torreAtaca(const Coordenada& curr) const {
    for (const auto& torre : torres) {
      if (torre.x == curr.x || torre.y == curr.y) return true;
    }
    return false;
  }

  bool alfilAtaca(const Coordenada& curr) const {
    for (const auto& alfil : alfiles) {
      if (std::abs(curr.x - alfil.x) == std::abs(curr.y - alfil.y)) return true;
    }
    return false;
  }
};

int main() {
  int n, k;
  std::cin >> n >> k;
  Coordenada reina;
  std::cin >> reina.x >> reina.y;

  Tablero t(n, reina.x, reina.y);

  for (int i = 0; i < k; i++) {
    char tipo;
    int x, y;
    std::cin >> tipo >> x >> y;

    if (tipo == 'T') t.torres.push_back({x, y});
    if (tipo == 'A') t.alfiles.push_back({x, y});
    if (tipo == 'C') t.caballos.push_back({x, y});
  }

  for (const auto& posicion : t.posiciones) {
    if (!t.caballoAtaca(posicion) && !t.alfilAtaca(posicion) &&
        !t.torreAtaca(posicion)) {
      std::cout << posicion.x << " " << posicion.y << "\n";
      return 0;
    }
  }

  std::cout << -1 << "\n";
  return 0;
}
