#include <iostream>

int main() {
  int t;
  std::cin >> t;
  // Si P[i] = 1 para toda i en [0, h], entonces cada segundo
  // gasta un pretzel. Como son [t] segundos, entonces
  // gastaríamos [t] pretzels.
  std::cout << t << "\n";
  return 0;
}
