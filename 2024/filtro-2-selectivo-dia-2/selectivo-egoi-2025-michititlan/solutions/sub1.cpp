// Sub1: Dado que todas las `X_i` son iguales, podemos simplemente checar que es
// mejor: moverse a esa calle vertical y entregar todos los platillos de golpe o
// entregar todos los platillos en sus respectivas calles horizontales.

#include <iostream>

int main() {
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int n;
  std::cin >> n;

  int x, y, prev_y;
  std::cin >> x >> prev_y;

  int distancia_y = prev_y;
  for (int i = 1; i < n; ++i) {
    std::cin >> x >> y;
    distancia_y += std::abs(y - prev_y);
    prev_y = y;
  }
  std::cout << std::min(std::abs(x), distancia_y) << '\n';
}
