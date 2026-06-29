/* Probar sacar minimo de solo los ultimos 2 numeros */
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  std::cout << std::min(c, d) << '\n';
  return 0;
}
