/* Asumir que todos los caracteres son iguales */
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  int n;
  char movimiento;
  std::cin >> n >> movimiento;

  switch (movimiento) {
    case '^':
      std::cout << "1 0\n";
      break;
    case 'v':
      std::cout << "-1 0\n";
      break;
    case '<':
      std::cout << "0 -1\n";
      break;
    case '>':
      std::cout << "0 1\n";
  }
}
