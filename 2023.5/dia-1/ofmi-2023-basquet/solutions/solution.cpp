#include <iostream>

int main() {
  // Leemos los 5 números a, b, c, d, e
  int a, b, c, d, e;
  std::cin >> a >> b >> c >> d >> e;

  // Vamos a probar todas las combinaciones de 3 números
  // En busca del primero que sume 100.
  // En total son 10 combinaciones

  // Primera combinación: a, b, c
  if (a + b + c == 100) {
    std::cout << a << ' ' << b << ' ' << c << '\n';
    return 0;
  }
  // Segunda combinación: a, b, d
  if (a + b + d == 100) {
    std::cout << a << ' ' << b << ' ' << d << '\n';
    return 0;
  }
  // Tercera combinación: a, b, e
  if (a + b + e == 100) {
    std::cout << a << ' ' << b << ' ' << e << '\n';
    return 0;
  }
  // Cuarta combinación: a, c, d
  if (a + c + d == 100) {
    std::cout << a << ' ' << c << ' ' << d << '\n';
    return 0;
  }
  // Quinta combinación: a, c, e
  if (a + c + e == 100) {
    std::cout << a << ' ' << c << ' ' << e << '\n';
    return 0;
  }
  // Sexta combinación: a, d, e
  if (a + d + e == 100) {
    std::cout << a << ' ' << d << ' ' << e << '\n';
    return 0;
  }
  // Séptima combinación: b, c, d
  if (b + c + d == 100) {
    std::cout << b << ' ' << c << ' ' << d << '\n';
    return 0;
  }
  // Octava combinación: b, c, e
  if (b + c + e == 100) {
    std::cout << b << ' ' << c << ' ' << e << '\n';
    return 0;
  }
  // Novena combinación: b, d, e
  if (b + d + e == 100) {
    std::cout << b << ' ' << d << ' ' << e << '\n';
    return 0;
  }
  // Décima combinación: c, d, e
  if (c + d + e == 100) {
    std::cout << c << ' ' << d << ' ' << e << '\n';
    return 0;
  }

  // Ninguna combinación sumó 100
  std::cout << -1 << '\n';
  return 0;
}
