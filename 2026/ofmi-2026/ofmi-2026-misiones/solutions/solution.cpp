#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;

  if (a <= b && a <= c && a <= d) {
    std::cout << a << '\n';
  } else if (b <= a && b <= c && b <= d) {
    std::cout << b << '\n';
  } else if (c <= a && c <= b && c <= d) {
    std::cout << c << '\n';
  } else {
    std::cout << d << '\n';
  }
}
