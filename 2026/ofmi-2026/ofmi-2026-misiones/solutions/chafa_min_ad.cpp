/* Probar sacar minimo de solo los extremos */
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  std::cout << std::min(a, d) << '\n';
  return 0;
}
