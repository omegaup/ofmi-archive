/* Probar sacar minimo de solo b y d */
#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  std::cout << std::min(b, d) << '\n';
  return 0;
}
