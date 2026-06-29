/* Probar no tener else */
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if (a < b && b < c && c < d) std::cout << a << "\n";
  if (b < a && a < c && c < d) std::cout << b << "\n";
  if (c < a && c < b && c < d) std::cout << c << "\n";
  if (d < b && b < c && d < a) std::cout << d << "\n";
  return 0;
}
