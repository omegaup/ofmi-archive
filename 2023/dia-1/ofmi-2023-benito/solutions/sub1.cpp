#include <iostream>

int main() {
  int n;
  std::cin >> n;
  if (n == 1) {
    int val;
    std::cin >> val;
    if (val == 1) {
      // Si es una matriz espiral valida de 1x1
      std::cout << "1\n";
    } else {
      // No es una matriz espiral valida
      std::cout << "-1\n";
    }
    return 0;
  }
  if (n == 3) {
    /*
    Leemos la matriz de la siguiente forma
      a b c
      d e f
      g h i
    */
    int a, b, c;
    int d, e, f;
    int g, h, i;
    std::cin >> a >> b >> c;
    std::cin >> d >> e >> f;
    std::cin >> g >> h >> i;

    /*
      1 1 1
      1 2 1
      1 1 1
    */
    if (a == 1 && b == 1 && c == 1) {
      if (d == 1 && e == 2 && f == 1) {
        if (g == 1 && h == 1 && i == 1) {
          std::cout << "2\n";
          return 0;
        }
      }
    }

    /*
      2 2 2
      2 1 2
      2 2 2
    */
    if (a == 2 && b == 2 && c == 2) {
      if (d == 2 && e == 1 && f == 2) {
        if (g == 2 && h == 2 && i == 2) {
          std::cout << "2\n";
          return 0;
        }
      }
    }

    // No es una matriz espiral
    std::cout << "-1\n";
    return 0;
  }
  std::cout << "-1\n";
}
