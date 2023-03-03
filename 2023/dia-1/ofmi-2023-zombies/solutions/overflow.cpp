#include <iostream>

int main() {
  int n, f, zombie = 0;
  int escudos = 0;
  std::cin >> n >> f;
  for (int i = 0; i < n; i++) {
    std::cin >> zombie;
    escudos += (zombie - 1) / f;
  }
  std::cout << escudos << std::endl;
  return 0;
}
