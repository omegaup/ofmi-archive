#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  std::cout << std::min(std::min(a, b), std::min(c, d)) << std::endl;
}
